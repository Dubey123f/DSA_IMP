#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    int ans=INT_MIN;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    // for(int i=0;i+k<=n;i++){
    //     int mn=INT_MAX;
    //     for(int j=i;j<i+k;j++){
    //         // cout<<arr[j]<<" ";
    //    mn=min(mn,arr[j]);
    //     }
    //     ans=max(ans,mn);

    // }
    // cout<<"The maximum of minimums is: "<<ans<<endl;
    deque<int>dq;
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]>=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
  if(i >= k - 1){
            ans = max(ans, arr[dq.front()]);
    }


    }
    cout<<ans<<endl;
    



}