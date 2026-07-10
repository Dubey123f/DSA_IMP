import cv2
import numpy as np
import mediapipe as mp

from mediapipe.tasks import python
from mediapipe.tasks.python import vision

BaseOptions = python.BaseOptions
HandLandmarker = vision.HandLandmarker
HandLandmarkerOptions = vision.HandLandmarkerOptions
VisionRunningMode = vision.RunningMode

model_path = "hand_landmarker.task"

options = HandLandmarkerOptions(
    base_options=BaseOptions(model_asset_path=model_path),
    running_mode=VisionRunningMode.VIDEO,
    num_hands=1
)

landmarker = HandLandmarker.create_from_options(options)

cap = cv2.VideoCapture(0)

canvas = None
prev_x, prev_y = 0, 0

def fingers_up(landmarks):
    fingers = []

    # Thumb (x comparison)
    fingers.append(1 if landmarks[4].x < landmarks[3].x else 0)

    # Index
    fingers.append(1 if landmarks[8].y < landmarks[6].y else 0)

    # Middle
    fingers.append(1 if landmarks[12].y < landmarks[10].y else 0)

    # Ring
    fingers.append(1 if landmarks[16].y < landmarks[14].y else 0)

    # Pinky
    fingers.append(1 if landmarks[20].y < landmarks[18].y else 0)

    return fingers

while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)

    if canvas is None:
        canvas = np.zeros_like(frame)

    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_frame)

    timestamp = int(cap.get(cv2.CAP_PROP_POS_MSEC))
    result = landmarker.detect_for_video(mp_image, timestamp)

    if result.hand_landmarks:
        landmarks = result.hand_landmarks[0]

        fingers = fingers_up(landmarks)

        h, w, _ = frame.shape
        cx, cy = int(landmarks[8].x * w), int(landmarks[8].y * h)

        # 👉 DRAW MODE (only index finger up)
        if fingers == [0,1,0,0,0]:
            if prev_x == 0 and prev_y == 0:
                prev_x, prev_y = cx, cy

            cv2.line(canvas, (prev_x, prev_y), (cx, cy), (255, 0, 255), 5)
            prev_x, prev_y = cx, cy

        # 👉 ERASE MODE (thumb up)
        elif fingers[0] == 1:
            cv2.circle(canvas, (cx, cy), 30, (0, 0, 0), -1)

            prev_x, prev_y = 0, 0

        else:
            prev_x, prev_y = 0, 0

    else:
        prev_x, prev_y = 0, 0

    # Merge canvas
    gray = cv2.cvtColor(canvas, cv2.COLOR_BGR2GRAY)
    _, inv = cv2.threshold(gray, 50, 255, cv2.THRESH_BINARY_INV)
    inv = cv2.cvtColor(inv, cv2.COLOR_GRAY2BGR)

    frame = cv2.bitwise_and(frame, inv)
    frame = cv2.bitwise_or(frame, canvas)

    cv2.imshow("Air Writing with Eraser 🔥", frame)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()