#include<bits/stdc++.h>
using namespace std;
// Recursive approach
int solve(int arr[],int i,int j){
    int mini=INT_MAX;
    if(i>=j){
        return 0;
    }
    for(int k=i;k<j;k++){
        int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
         mini=min(mini,tempans);
    }
       
    return mini;
}


int main(){
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the dimensions of the matrices: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The minimum number of multiplications is: "<<solve(arr,1,n-1)<<endl;

}