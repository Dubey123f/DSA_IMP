#include<bits/stdc++.h>
using namespace std;
 void reverse(string &s,int l,int r){
         while(l<r){
            swap(s[l++],s[r--]);
         }  
    }
int main(){
   
    string s="I Love Coding";
    
    // vector<string>words;
    // string temp="";
    // for(char c:s){
    //     if(c==' '){
    //         words.push_back(temp);
    //         temp="";
    //     }
    //     else{
    //         temp+=c;
    //     }
    // }
    //  words.push_back(temp);
    //  for(int i=words.size()-1;i>=0;i--){
    //     cout<<words[i];
    //     if(i!=0){
    //         cout<<" ";
    //     }
    //  }
    reverse(s,0,s.size()-1);
    int st=0;
    for(int i=0;i<=s.size();i++){
        if(i==s.size()||s[i]==' '){
            reverse(s,st,i-1);
            st=i+1;
        }
    }
cout<<s;  
}