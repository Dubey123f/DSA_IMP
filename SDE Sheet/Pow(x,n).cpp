#include<bits/stdc++.h>
using namespace std;
double power(double x,int n){
    if(n==0){
        return 1.0;
    }
    if(n==1){
        return x;
    }
   if(n%2==0){
    return power(x*x,1LL*(n/2));
   }
   else{
    return x*power(x,1LL*(n-1));
   }
    if(n<0){
     return 1/power(x,-n);
    }
    else{
     return power(x,n);

}
}
int main(){
    double x;
    int n;
    cout<<"Enter the base (x): ";
    cin>>x;
    cout<<"Enter the exponent (n): ";
    cin>>n;
    // double result=1.0;
    // int i=0;
    // if(n<0){
    //     x=1/x;
    //     n=-n;
    // }
    // while(i<n){
    //     result=result*x;
    //     i++;
    // }
    // cout<<"The result of Pow("<<x<<","<<n<<") is: "<<result<<endl;
  if(n==0){
    cout<<"The result of Pow("<<x<<","<<n<<") is: "<<1.0<<endl;
  }
  if(n==1){
    cout<<"The result of Pow("<<x<<","<<n<<") is: "<<x<<endl;
  }
    double result=power(x,n);
    cout<<"The result of Pow("<<x<<","<<n<<") is: "<<result<<endl;



}