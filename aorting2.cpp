#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the value of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
  // Selection Sort Algorithm
  // Time Complexity: O(n^2)
//  for(int i=0;i<n;i++){
//     int mini=i;
//     for(int j=i+1;j<n;j++){
//         if(arr[j]<arr[mini]){
//             mini=j;
//         }
//     }
//     // swap(arr[i], arr[mini]);
//     int t=arr[i];
//     arr[i]=arr[mini];
//     arr[mini]=t;
//  }
for(int i=0;i<n;i++){
    int j=i;
    while(j>0 && arr[j]<arr[j-1]){
        int t=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=t;
        j--;
    }
}
cout<<"Sorted array looks like after Insertion sort: ";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}