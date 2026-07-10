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
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    vector<vector<int>>res;
    //Brute Force Approach
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         for(int k=j+1;k<n;k++){
    //             for(int l=k+1;l<n;l++){
    //                 if(nums[i]+nums[j]+nums[k]+nums[l]==target){
    //                     cout<<"The indices of the four numbers that add up to the target are: "<<i<<", "<<j<<", "<<k<<", "<<l<<endl;
    //                     res.push_back({nums[i],nums[j],nums[k],nums[l]});
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout<<"The quadruplets that add up to the target are: "<<endl;
    // for(auto quad:res){
    //     cout<<"["<<quad[0]<<", "<<quad[1]<<", "<<quad[2]<<", "<<quad[3]<<"] ";
    // }
    // cout<<endl;
    //Optimal Approach using sorting and two pointer technique
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int l=j+1;
            int r=n-1;
            while(l<r){
                int s=nums[i]+nums[j]+nums[l]+nums[r];
                if(s==target){
                    res.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]){
                        l++;
                    }
                    while(l<r && nums[r]==nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;

                }
                else if(s<target){
                    l++;
                }
                else{
                    r--;
                }

            }
        }
    }
    //Removing Duplicates
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    cout<<"The quadruplets that add up to the target are: "<<endl;
    for(auto quad:res){
        cout<<"["<<quad[0]<<", "<<quad[1]<<", "<<quad[2]<<", "<<quad[3]<<"] ";
    }
}