// 453. Minimum Moves to Equal Array Elements
// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment n - 1 elements of the array by 1.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 3
// Explanation: Only three moves are needed (remember each move increments two elements):
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
// Example 2:

// Input: nums = [1,1,1]
// Output: 0

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int minElement=*min_element(nums.begin(),nums.end());
    long long moves=0;
    for(int i=0;i<n;i++){
        moves+=nums[i]-minElement;

    }
    cout<<"Minimum number of moves to make all array elements equal: "<<moves<<endl;
    return 0;
}