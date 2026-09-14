class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int left=max(ax1,bx1);
        int right=min(ax2,bx2);
        int top=max(ay1,by1);
        int bottom=min(ay2,by2);
        int w=max(0,right-left);
        int h=max(0,bottom-top);
         long long o=0;
        if(right>left && top<bottom){
         o=(long long)w*(long long)h;
        }
        long long a1=(long long)(ax2-ax1)*(ay2-ay1);
        long long a2=(long long)(bx2-bx1)*(by2-by1);
        long long a=(a1+a2)-o;
        return a;
    }
};