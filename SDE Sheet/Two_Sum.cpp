#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    //Brute Force Approach
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]+nums[j]==target){
    //             cout<<"The indices of the two numbers that add up to the target are: "<<i<<" and "<<j<<endl;

    //         }
    //     }
    // }
    //Better approach using hash map
    // map<int,int>mp;
    // for(int i=0;i<n;i++){
    //     int c=target-nums[i];
    //     if(mp.find(c)!=mp.end()){
    //         cout<<"The indices of the two numbers that add up to the target are: "<<mp[c]<<" and "<<i<<endl;
    //     }
    //     else{
    //         mp[nums[i]]=i;
    //     }
    // }
    //Optimal Approach using two pointer technique
    int l=0;
    int r=n-1;
    // sort(nums.begin(),nums.end());
    while(l<r){
        int sum=nums[l]+nums[r];
        if(sum==target){
            cout<<"The indices of the two numbers that add up to the target are: "<<l<<" and "<<r<<endl;
            break;
        }
       else if(sum<target){
        l++;
       }
       else {
        r--;
       }
    }

}