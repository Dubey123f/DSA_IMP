/* || RECURSION || */
// When a function calls itself untill a specified condition is met.
#include<bits/stdc++.h>
using namespace std;

void printName(int i,int n){
    cout<<"Ayush"<<endl;
   if(i>n){
    return;
   }
    printName(i+1,n);
}
void printNum(int i,int n){

if(i>n){
    return;
}
cout<<i;
printNum(i+1,n);
}
void revNum(int i,int n){
    if(i<1){
       return;
    }
    cout<<i;
    revNum(i-1,n);
}
void backTrack(int i,int n){
    if(i<1){
        return;
    }
    backTrack(i-1,n);
    cout<<i;
}
void backTrackRev(int i,int n){
    if(i>n){
        return;

    }
    backTrackRev(i+1,n);
    cout<<i;
}
void sumofN(int i,int sum){// parameterized way
    if(i<1){
        cout<<sum;
        return;
    }
    sumofN(i-1,sum+i);
}
int sumofNFunc(int n){ // functional way to implement recursion
    if(n==0){
        return 0;
    }
    else{
        return n+sumofNFunc(n-1);
    }
}
int factorial(int n){
    if(n==0){
        return 0;
        
    }
  else  if(n==1){
            return 1;
        }
    else{
        return n*factorial(n-1);
    }
}
void reverseArray(int l,int a[],int r){
    // this is using two pointer method
    if(l>=r){
        return;
    }
    swap(a[l],a[r]);
    reverseArray(l+1,a,r-1);
}
void reverseArrayOne(int i,int a[],int n){
    // this is using one pointer
    if(i>=n/2){
        return;
    }
    swap(a[i],a[n-i-1]);
    reverseArrayOne(i+1,a,n);
}
bool checkPalindrome(int i,string &s){
    
    if(i>=s.size()/2){
        return true;
    }
    if(s[i]!=s[s.size()-i-1]){
        return false;
    }
    return checkPalindrome(i+1,s);
}
int fibonacci(int n){
    if(n<=1){
        return n;
    }
   int  last=fibonacci(n-1);
    int slast=fibonacci(n-2);
    return last+slast;
}

int main(){
//     int n,i;
//     string s[1222];
//     cin>>n;
// for(i=0;i<n;i++){
//     cin>>s[i];
// }
// cout<<"Your string is:"<<endl;
// for(i=0;i<n;i++){
//     cout<<s[i];
// }
// cout<<endl;
// cout<<"The swapped array is:"<<endl;
// printName(1,n);
// cout<<endl;
// printNum(1,n);
// cout<<endl;
// revNum(n,n);
// cout<<endl;
// backTrack(n,n);
// cout<<endl;
// backTrackRev(1,n);
// cout<<endl;
// sumofN(n,0);
// cout<<endl;
// cout<<sumofNFunc(n);
// cout<<endl;
// cout<<factorial(n);
// reverseArray(0,a,n-1);
// for(i=0;i<n;i++){
//     cout<<a[i];
// }
// cout<<endl;
// reverseArrayOne(0,a,n);
// for(i=0;i<n;i++){
//     cout<<a[i];
// }
// string s;
// cin>>s;
// cout<<checkPalindrome(0,s);
int n;
cin>>n;
cout<<fibonacci(n);
}