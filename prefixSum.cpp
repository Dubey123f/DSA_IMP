#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
int p=1;
vector<int>v;
for(int i=0;i<n;i++){
    p=p*nums[i];


}
v.push_back(p);
    cout<<"The product array is: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}