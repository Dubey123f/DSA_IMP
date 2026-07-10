// Given a link list, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be the same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one

#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* convertArrtoLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* divide(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    vector<int> arr;
    vector<int> arr2;
    Node* t = head;
    while (t) {
        if (t->data % 2 == 0) {
            arr.push_back(t->data);
        }
        else {
            arr2.push_back(t->data);
        }
        t = t->next;
    }
    for (int i = 0; i < arr2.size(); i++) {
        arr.push_back(arr2[i]);
    }
    
    Node* newHead = convertArrtoLL(arr);
    Node* temp = head;
    return newHead;
}
int main() {
    vector<int> arr = {17, 15, 8, 9, 2, 4, 6};
    Node* head = convertArrtoLL(arr);
    cout << "Original Linked List: ";
    print(head);
    
    head = divide(head);
    cout << "Modified Linked List: ";
    print(head);
    
    return 0;
}
