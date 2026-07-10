// Anirudh is attending an astronomy lecture. His professor who is very strict asks students to
// Write a program to print the trapezium pattern using stars and dots as shown below . Since Anirudh is not good at astronomy can you help him?

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<string(n-i-1,'*');
        cout<<string(2*i+1,'.');
        cout<<string(n-i-1,'*');
        cout<<endl;
    }
    for(int i=n-2;i>=0;i--){
        cout<<string(n-i-1,'*');
        cout<<string(2*i+1,'.');
        cout<<string(n-i-1,'*');
        cout<<endl;
    }
    return 0;

}