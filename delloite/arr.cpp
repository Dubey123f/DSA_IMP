#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++ ){
        cin>>arr[i];
    }
    int maxi=INT_MIN;
    if(x==1){
         maxi=*max_element(arr.begin(),arr.end());
        cout<<maxi;
    }
    else if(x==n){
        cout<<*min_element(arr.begin(),arr.end());
        
    }
else{
    //subarray of size x
    for(int i=0;i<=n-x;i++){
        int mini=INT_MAX;
        for(int j=i;j<i+x;j++){
            mini=min(mini,arr[j]);
        }
        maxi=max(maxi,mini);
    }
    cout<<maxi;
}
    
    return 0;


    
}