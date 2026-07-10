#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;
    int n=s1.size();
    int m=s2.size();
    string res="";
    for(int i=0,j=0;i<n,j<m;i++,j++){
        res+=s1[i];
        res+=s2[j];
    }
    if(n>m){
        res+=s1.substr(m,n-m);
    }
    else if(m>n){
        res+=s2.substr(n,m-n);
    }
    cout<<"The merged password is: "<<res<<endl;
}