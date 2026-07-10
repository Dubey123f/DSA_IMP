#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;

//     *
//    ***
//   *****
//  *******
// *********
// For upper Pyramid
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n-i;j++){
            cout<<" ";
         }
         for(int j=1;j<=2*i-1;j++){
            cout<<"*";
         }
         cout<<endl;
    }
//  *******
//   *****
//    ***
//     *
//For lower Pyramid
   for(int i=n-1;i>=1;i--){
    for(int j=1;j<=n-i;j++){
        cout<<" ";
    }
    for(int j=1;j<=2*i-1;j++){
        cout<<"*";
    }
    cout<<endl;
   }
}