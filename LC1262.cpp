// 1262. Greatest Sum Divisible by Three
// Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

 

// Example 1:

// Input: nums = [3,6,5,1,8]
// Output: 18
// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
// Example 2:

// Input: nums = [4]
// Output: 0
// Explanation: Since 4 is not divisible by 3, do not pick any number.
// Example 3:

// Input: nums = [1,2,3,4,4]
// Output: 12
// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 

// Constraints:

// 1 <= nums.length <= 4 * 104
// 1 <= nums[i] <= 104
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
    int dp[3]={0,INT_MIN,INT_MIN};
    for(int num:nums){
        int temp[3];
        for(int i=0;i<3;i++){
            temp[i]=dp[i];

            
        }
        for(int i=0;i<3;i++){
            int newMod=(i+num%3)%3;
            temp[newMod]=max(temp[newMod],dp[i]+num);

        }
        for(int i=0;i<3;i++){
            dp[i]=temp[i];
        }
    }
    cout << dp[0] << endl;
}