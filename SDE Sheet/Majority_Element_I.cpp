#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // Optimal Approach
    int cnt=0;
    int el=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el){
            cnt1++;
        }

    }
    if(cnt1>n/2){
        cout<<"The Majority Element is: "<<el<<endl;
    }
    else{
        cout<<"No Majority Element Found"<<endl;
    }
// }

//Better Approach
// map<int,int>mp;
// for(int i:arr){
//     mp[i]++;
//     if(mp[i]>n/2){
//         cout<<"The Majority Element is: "<<i<<endl;
//         return 0;
// }
// }
}