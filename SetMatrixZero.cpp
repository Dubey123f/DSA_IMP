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
   vector<bool>row(n,false);
   vector<bool>col(m,false);
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(matrix[i][j]==0){
            row[i]=true;
            col[j]=true;
        }
    }

   }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(row[i] || col[j]){
            matrix[i][j]=0;
        }

    }

   }
   

    cout<<"Matrix after setting zeros: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
