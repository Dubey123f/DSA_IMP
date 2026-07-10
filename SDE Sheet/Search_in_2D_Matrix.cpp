#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows and columns: ";
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int target;
    cout<<"Enter the target element to search: ";
    cin>>target;
    int low=0;
    int high=n*m-1;
    bool found=false;
    while(low<=high){
        int mid=(low+high)/2;
        int mid_value=matrix[mid/m][mid%m];
        if(mid_value==target){
            found=true;
            break;

        }
        else if(mid_value<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(found){
        cout<<"The target element "<<target<<" is found in the matrix."<<endl;
    }
    else{
        cout<<"The target element "<<target<<" is not found in the matrix."<<endl;
    }

}