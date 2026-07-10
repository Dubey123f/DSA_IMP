#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&nums,int left,int right,int mid){
    vector<int>temp;
    int l=left;
    int r=mid+1;
    while(l<=mid && r<=right){
        if(nums[l]<=nums[r]){
            temp.push_back(nums[l]);
            l++;
        }
        else{
            temp.push_back(nums[r]);
            r++;
        }
        
    }
    while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=right){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
}
int countPairs(vector<int>&nums,int left,int right,int mid){
    int c=0;
    int r=mid+1;
    for(int i=left;i<=mid;i++){
        while(r<=right && nums[i]>2LL*nums[r]){
            r++;
        }
        c+=r-(mid+1);
    }
    return c;
}
int mergeSort(vector<int>&nums,int left,int right){
    int c=0;
    if(left>=right){
        return c;
    }
    int mid=(left+right)/2;
    c+=mergeSort(nums,left,mid);
    c+=mergeSort(nums,mid+1,right);
    c+=countPairs(nums,left,right,mid);
    merge(nums,left,right,mid);
    return c;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result=mergeSort(nums,0,n-1);
    cout<<"The number of Reverse Pairs in the array is: "<<result<<endl;
    // int c=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]>2*nums[j]){
    //             cout<<"Reverse Pair Found: ("<<nums[i]<<", "<<nums[j]<<")"<<endl;
    //             c++;
    //         }
    //     }

    // }
    // cout<<"The number of Reverse Pairs in the array is: "<<c<<endl;

}