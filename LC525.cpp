// 525. Contiguous Array
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Example 3:

// Input: nums = [0,1,1,1,1,1,0,0,0]
// Output: 6
// Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of ther binary array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements in the binary array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int>map;
    int count=0;
    int maxL=0;
    map[0]=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            count--;
        }
        else{
            count ++;
        }
        if(map.find(count)!=map.end()){
            maxL=max(maxL,i-map[count]);
        }
        else{
            map[count]=i;
        }

    }
    cout<<"The maximum length of a contiguous subarray with equal number of 0 and 1 is: "<<maxL<<endl;
}