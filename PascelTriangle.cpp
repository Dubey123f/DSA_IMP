#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    vector<vector<int>>triangle(n);
    for(int i=0;i<n;i++){
        triangle[i].resize(i+1);
        triangle[i][0]=1;
        triangle[i][i]=1;
        for(int j=1;j<i;j++){
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];

        }

    }
    cout<<"Pascal's Triangle: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<triangle[i].size();j++){
            cout<<triangle[i][j]<<" ";
        }
        cout<<endl;
    }

}