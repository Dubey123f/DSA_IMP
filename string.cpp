Ques:1-// Longest Substring without repeating the character.


// #include <bits/stdc++.h> 
// int uniqueSubstrings(string input)
// {
//     //Write your code here
//     int l=0,r=0,n=input.size(),m=0;
//     int hash[256];
//  fill(hash, hash+256, -1); 
//     while(r<n){
//         if(hash[input[r]]!=-1){
//             if(hash[input[r]]>=l){
//                 l=hash[input[r]]+1;
//             }
//         }
// m=max(m,r-l+1);
// hash[input[r]]=r;
// r++;
//     }
//     return m;
// }

 Ques:3- // Maximum Consecutive ones III

// int longestSubSeg(vector<int> &arr , int n, int k){
//     // Write your code here.
//     int l=0,r=0,m=0,z=0;
//     while(r<n){
//         if(arr[r]==0){
//             z++;
//         }
//         while(z>k){
//             if(arr[l]==0){
//                 z--;
//             }
//             l++;
//         }
//         if(z<=k){
//             m=max(m,r-l+1);
//         }
//         r++;
//     }
//     return m;
// }
