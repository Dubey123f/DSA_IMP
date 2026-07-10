#include<iostream>
using namespace std;
void me(int arr[],int n){
arr[0]+=100;
cout<<"The value:"<<arr[0]<<endl;
}
int main(){
int n=5;
int arr[n],i;
for(i=0;i<n;i++){
    cin>>arr[i];
}
me(arr,n);
cout<<"The value is:"<<arr[0]<<endl;
return 0;
}
// Array always goes with pass by reference.
// Here the original value of a[0] should be 2 but due to pass by reference it  will be 102.