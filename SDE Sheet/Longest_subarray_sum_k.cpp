#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"Enter the target sum k: ";
    cin>>k;
    //Brute Force Approach
    // int max=0;
    // int l=0;
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=nums[j];
    //         if(sum==k){
    //             int l=j-i+1;
    //             max=(l>max)?l:max;
    //         }

    //     }

    // }
    // cout<<"The length of the longest subarray with sum k is: "<<max<<endl;
    //Optimal Approach using hashmap
    map<int,int>mp;
    int s=0;
    int maxL=0;
    for(int i=0;i<n;i++){
        s+=nums[i];
        if(s==k){
            maxL=i+1;

        }
        if(mp.find(s)==mp.end()){
            mp[s]=i;
        }
        if(mp.find(s-k)!=mp.end()){
            maxL=max(maxL,i-mp[s-k]);
            
        }

    }
    cout<<"The length of the longest subarray with sum k is: "<<maxL<<endl;
}
