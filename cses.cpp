#include <bits/stdc++.h>
using namespace std;
int countDis(vector<int>&arr,int n){
    // int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<high){
        if(arr[low]==arr[high]){
            low++;
            high--;
        }
        else{
            return 0;
        }
    }

}

int main(){
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<countDis(arr,n);

return 0;

}

