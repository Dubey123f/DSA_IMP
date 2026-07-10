// 3381. Maximum Subarray Sum With Length Divisible by K
// You are given an array of integers nums and an integer k.

// Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

 

// Example 1:

// Input: nums = [1,2], k = 1

// Output: 3

// Explanation:

// The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

// Example 2:

// Input: nums = [-1,-2,-3,-4,-5], k = 4

// Output: -10

// Explanation:

// The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

// Example 3:

// Input: nums = [-5,1,2,-3,4], k = 2

// Output: 4

// Explanation:

// The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

 

// Constraints:

// 1 <= k <= nums.length <= 2 * 105
// -109 <= nums[i] <= 109
 

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the size of the array: ";
//     cin>>n;
//     vector<int>nums(n);
//     cout<<"Enter the elements int the array: ";
//     for(int i=0;i<n;i++){
//         cin>>nums[i];

//     }
//     int k;
//     cout<<"Enter the value of the k: ";
//     cin>>k;
//     long long maxSum=LONG_LONG_MIN;
//     for(int i=0;i<n;i++){
//         long long currentSum=0;
//         for(int j=i;j<n;j++){
//             currentSum+=nums[j];
//             if((j-i+1)%k==0){
//                 maxSum=max(maxSum,currentSum);

//             }

//         }

//     }
//     cout<<"The maximum sum of a subarray of nums, such that the size of the subarray is divisible by k is: "<<maxSum<<endl;
// }



// Optimized Solution:-
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
    cout<<"Enter the value of the K: ";
    cin>>k;
    vector<long long>dp(k,LLONG_MIN);
    dp[0]=0;
    long long cs=0;
    long long ms=LLONG_MIN;
    for(int i=0;i<n;i++){
        cs+=nums[i];
        int r=cs%k;
        if(r<0){
            r+=k;

        }
        if(dp[r]!=LLONG_MIN){
            ms=max(ms,cs-dp[r]);
            
        }
         if (dp[r] == LLONG_MIN)
                dp[r] = cs;
            else
                dp[r] = min(dp[r], cs);

    }
    cout<<"The maximum sum of a subarray of nums, such that the size of the subarray is divisible by k is: "<<ms<<endl;
}