// Without uisng extra space, merge two sorted arrays.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the size of the first and second arrays: ";
    cin>>n>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    cout<<"Enter the elements of the first sorted array: ";
    for(int i=0;i<n+m;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the elements of the second sorted array: ";
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
   int i=n-1;
   int j=m-1;
   int k=n+m-1;
   while(i>=0 && j>=0){
    if(arr1[i]>arr2[j]){
        arr1[k]=arr1[i];
        i--;
        k--;
    }
    else{
        arr1[k]=arr2[j];
        j--;
        k--;
    }

   }
    while(j>=0){
     arr1[k]=arr2[j];
     j--;
     k--;
    }
    cout<<"The Merged Sorted Array is: ";
    for(int i=0;i<n+m;i++){
        cout<<arr1[i]<<" ";
    }
    


}