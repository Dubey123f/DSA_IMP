#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cout<<"Enter the string: ";
cin>>s;
int l=0,ans=0;
int r=0;
unordered_set<int>st;
for(r=0;r<s.size();r++){
    while(st.find(s[r])!=st.end()){
        st.erase(s[l]);
        l++;

    }
    st.insert(s[r]);
    ans=max(ans,r-l+1);

}
cout<<"The longest substring length is: "<<ans<<endl;
cout<<"The longest substring is: ";






}