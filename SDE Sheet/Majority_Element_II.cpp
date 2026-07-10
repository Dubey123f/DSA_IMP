#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>res;
    int c1=0,c2=0;
    int e1=INT_MIN,e2=INT_MIN;
    for(int i=0;i<n;i++){
        if(c1==0 && nums[i]!=e2){
            c1++;
            e1=nums[i];
        }
        else if(c2==0 && nums[i]!=e1){
            c2++;
            e2=nums[i];
        }
        else if(nums[i]==e1){
            c1++;
        }
        else if(nums[i]==e2){
            c2++;
        }
          else{
        c1--;
        c2--;
    }
    }
    int c11=0,c22=0;
    for(int i=0;i<n;i++){
        if(nums[i]==e1){
            c11++;
        }
        if(nums[i]==e2 && e2!=e1){
            c22++;
        }
    }
    if(c11>n/3){
        res.push_back(e1);
    }
    if(c22>n/3){
        res.push_back(e2);
    }
    if(res.size()==0){
        cout<<"No Majority Element Found"<<endl;
    }
    else{
        cout<<"The Majority Elements are: ";
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
  

}