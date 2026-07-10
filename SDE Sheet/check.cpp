#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the value of n and m: ";
    cin>>n>>m;
    vector<int>apple(n);
    vector<int>capacity(m);
    cout<<"Enter the number of apples in each pile: ";
    for(int i=0;i<n;i++){
        cin>>apple[i];
    }
    cout<<"Enter the capacity of each basket: ";
    for(int i=0;i<m;i++){
        cin>>capacity[i];
    }
    sort(capacity.begin(),capacity.end());
    int s=0;
    for(int i=0;i<n;i++){
        s+=apple[i];
    }
    for(int i=m-1;i>=0;i--){
        if(s>=capacity[i]){
            s-=capacity[i];
        }
        else{
            capacity[i]=s;
            s=0;
            break;
        }
    }
    cout<<"The distribution of apples in each basket is: ";
    for(int i=0;i<m;i++){
        cout<<capacity[i]<<" ";
    }
}