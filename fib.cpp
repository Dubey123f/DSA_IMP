#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[4000];
    int n;
    int i;
    cin>>n;
    // if(n==2){
    //     cout<<"2"<<endl;
    // }
for(i=1;i<=n-1;i++){
    cin>>a[i];
}
cout<<endl;
for(i=1;i<=n-1;i++){
    cout<<a[i];
}
cout<<endl;
for(i=1;i<=n-1;i++){
    if(a[i]!=i){
cout<<i;
    }
}
}

