#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    for(int x:arr){
        mp[x]++;
        if(mp[x]>1){
            cout<<"The Duplicate Element is: "<<x<<endl;
            break;
        }
    }
}