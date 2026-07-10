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
    cout<<"The elements in the array are: ";
   for(int i=0;i<nums.size();i++){
       cout<<nums[i]<<" ";
   }
   vector<int>pr(nums.size());
   pr[0]=nums[0];
   int s=0;
   int c=0;
   for(int i=1;i<nums.size();i++){
     s=accumulate(nums.begin()+i,nums.end(),0);
     cout<<"The sum of the array is: "<<s<<endl;
     int d=pr[i-1]-s;
   cout<<"The difference between previous sum and current sum is: "<<d<<endl;
   if(d%2==0){
    c++;
   }
   cout<<"The count of the subarrays is: "<<c<<endl;   
    pr[i]=pr[i-1]+nums[i];
    s=s-nums[i];
  

   }


}