#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n){
    int i,j;
    for(i=0;i<=n-2;i++){
        int m=i;
        for(j=i;j<=n-1;j++){
            if(arr[j]<arr[m]){
                m=j;
            }

        }
        // int t=arr[m];
        // arr[m]=arr[i];
        // arr[i]=t;
        swap(arr[i],arr[m]);
    }
    cout<<"The array after sorting looks like:"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void bubble_sort(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            int t=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=t;
          
        }
    }
    cout<<"After Performing Bubble sort:"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void insertion_sort(int arr[],int n){
    int i,j;
    for(i=0;i<n;i++){
        j=i;
        while(j>0&&arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    cout<<"The array after insertion sorting is:"<<endl;
     for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
}
}
// MERGE SORT
void merge(vector<int>&arr,int low,int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }

    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void merge_sort(vector<int>&arr,int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
// QUICK SORT
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
swap(arr[low],arr[j]);
return j;
    }
void quick_Sort(vector<int>&arr,int low,int high){
    if(low<high){
        int partIndex=partition(arr,low,high);
        quick_Sort(arr,low,partIndex-1);
        quick_Sort(arr,partIndex+1,high);
    }
}
int main(){
    // int n,i,arr[600];   
    // cout<<"Enter n:"<<endl;
    // cin>>n;
    // cout<<"Enter the elements in arrar:"<<endl;
    // for(i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // cout<<"The array Before sorting is:"<<endl;
    //  for(i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // selection_sort(arr,n);
    // // for(i=0;i<n;i++){
    // //     cout<<arr[i]<<" ";
    // // } 
    //  cout<<endl;
    // bubble_sort(arr,n);
    //   cout<<endl;
    // insertion_sort(arr,n);
    vector<int>arr={9,8,7,12,46,5,0};
    int n=7;
    cout<<"Before sorting, the array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   
    merge_sort(arr,0,n-1);
          cout<<"After Merge sorting, the array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quick_Sort(arr,0,n-1);
           cout<<"After Quick sorting, the array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}