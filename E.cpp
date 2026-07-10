#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1 || i==2){
            cout<<"****\n";
        }
        else{
            cout<<"*\n";
        }
    }
}