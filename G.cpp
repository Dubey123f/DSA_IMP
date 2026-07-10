#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the valuse of n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1){
            cout<<"****\n";
        }
        else if(i==2){
            cout<<"*  **\n";
        }
        else if(i==3){
            cout<<"*   *\n";
        }
        else{
            cout<<"*\n";
        }
    }
}