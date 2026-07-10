#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    int p=1;
    for(int i=a;i<=b;i++){
        p*=i;
    }
    int e=0;
    while(p%10==0){
        p/=10;
        e++;
    }
  
    cout<<"The product of numbers from a to b is: "<<p<<"X"<<"10^"<<e<<endl;
}