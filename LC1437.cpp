// 1437. Check If All 1's Are at Least Length K Places Away
// Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

 

// Example 1:


// Input: nums = [1,0,0,0,1,0,0,1], k = 2
// Output: true
// Explanation: Each of the 1s are at least 2 places away from each other.
// Example 2:


// Input: nums = [1,0,0,1,0,1], k = 2
// Output: false
// Explanation: The second 1 and third 1 are only one apart from each other.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= k <= nums.length
// nums[i] is 0 or 1

//Solution:-
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
int k;
cout<<"Enter the value of k: ";
cin>>k;
int lastOneIndex = -1;
for(int i=0;i<n;i++){
    if(nums[i]==1){
        if(lastOneIndex!=-1 && i-lastOneIndex-1<k){
            cout<<"false"<<endl;
        }
        lastOneIndex=i;


    }
    }
cout<<"true"<<endl;
return 0;
}
