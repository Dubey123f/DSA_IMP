#include<bits/stdc++.h>
using namespace std;
int main(){
    //Array Hashing
  /*  int i,n,a[14];
    cout<<"Enter N:"<<endl;
    cin>>n;
     cout<<"Enter array:"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int hsh[14]={0};
    for(i=0;i<n;i++){
        hsh[a[i]]+=1;
    }
    int q;
     cout<<"Enter q:"<<endl;
    cin>>q;
    while(q--){
        int n2;
        
cout<<"Enter n2:"<<endl;
        cin>>n2;
      cout<<hsh[n2];
    }*/
   //String Hashing
   /*int i;
   char c;
   int co=0;
   string s;
   cin>>s;
int hash[26]={0};
for(i=0;i<s.size();i++){
    hash[s[i]-'a']++;
}
 

   int q;
   cin>>q;
   while(q--){
   
    cin>>c;
cout<<hash[c-'a'];

   }

 


cout<<endl;*/
// Array hashing using Map 
/*int n,i,a[200];
cin>>n;
for(i=0;i<n;i++){
    cin>>a[i];

}
map<int,int>mpp;
for(i=0;i<n;i++){
    mpp[a[i]]++;
}


int q;
cin>>q;
while(q--){
    int n2;
    cin>>n2;
cout<<mpp[n2];
}*/
// String hashing using map
int i;
string s;
cin>>s;
map<char,int>mpp;
for(i=0;i<s.size();i++){
    mpp[s[i]]++;
}
int q;
cin>>q;
while(q--){
    char c;
    cin>>c;
    cout<<mpp[c];
}
    return 0;
}