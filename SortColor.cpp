#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array (0s, 1s and 2s only): ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,m=0,h=n-1;
    while(m<=h){
        if(arr[m]==0){
            l++;
            m++;
        }
        else if(arr[m]==1){
            m++;
        }
        else{
            swap(arr[m],arr[h]);
            h--;
        }
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}