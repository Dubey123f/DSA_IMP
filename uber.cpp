#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,0,2,0,3,0,5,0};
    // vector<int>res;
    // for(int i=0;i<arr.size();i++){
    //     if(arr[i]!=0){
    //         res.push_back(arr[i]);
    //     }
    // }
    // int zc=arr.size()-res.size();
    // while(zc--){
    //     res.push_back(0);
    // }
    // for(int x:res){
    //     cout<<x<<" ";
    // }

    int j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j++;
        }
    }
    while(j<arr.size()){
        arr[j]=0;
        j++;
    }
    for(int x:arr){
        cout<<x<<" ";
    }
}