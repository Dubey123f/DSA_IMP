#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j=arr[0];
    int s=arr[0];
    for(int i=1;i<n;i++){
j=max(arr[i],j+arr[i]);
s=max(s,j);
    }
    cout<<"Maximum Subarray Sum: "<<s<<endl;
}