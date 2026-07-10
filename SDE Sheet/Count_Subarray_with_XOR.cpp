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
int xore;
cout<<"Enter the target XOR value: ";
cin>>xore;
//Brute Force Approach
// int c=0;
// for(int i=0;i<n;i++){
//     int currXor=0;
//     for(int j=i;j<n;j++){
//         currXor=currXor^nums[j];
//         if(xore==currXor){
//             c++;
//         }
//     }
// }
// cout<<"Count of subarrays with given XOR is: "<<c<<endl;
//Optimal Approach using hashmap
map<int,int>mp;
int currXor=0;
int c=0;
for(int i=0;i<n;i++){
    currXor=currXor^nums[i];
    if(currXor==xore){
        c++;
    }
    int h=currXor^xore;
    if(mp.find(h)!=mp.end()){
        c+=mp[h];
    }
    mp[currXor]++;
}
cout<<"Count of subarrays with given XOR is: "<<c<<endl;
}