// 813. Largest Sum of Averages
// You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.

// Note that the partition must use every integer in nums, and that the score is not necessarily an integer.

// Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.

 

// Example 1:

// Input: nums = [9,1,2,3,9], k = 3
// Output: 20.00000
// Explanation: 
// The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
// We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
// Example 2:

// Input: nums = [1,2,3,4,5,6,7], k = 4
// Output: 20.50000
 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 104
// 1 <= k <= nums.length
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements in  the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    vector<double>dp(n+1,0.0);
    vector<double>prefix(n+1,0.0);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+nums[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=n-1;j>=0;j--){
            for(int p=j+1;p<=n;p++){
                dp[j]=max(dp[j],(prefix[p]-prefix[j])/(p-j)+dp[p]);
            
            
}
}
} 
cout<<"The maximum score is: "<<fixed<<setprecision(6)<<dp[0]<<endl;
}