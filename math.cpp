#include<bits/stdc++.h>
using namespace std;
int counDigit(int n){
//  int c=int(log10(n)+1);
int c=0,l;
    while(n>0){

        l=n%10;
        n=n/10;
         cout<<l<<endl;
         c++;
    }
  return c;
}
int revNumber(int n){
    int rev=0;
    while(n>0){
        int l=n%10;
        n=n/10;
        rev=((rev*10)+l);
    }
    return rev;
}
int palindrome(int n){
    int x=n;
    int rev=0;
    while(n>0){
        int l=n%10;
        n=n/10;
        rev=((rev*10)+l);
    }
    if (x==rev){
        cout<<"The number is palindrome"<<endl;
    }
    else{
        cout<<"Not";
    }
    }
int ArmstrongNum(int n){
    int dup=n;
    int sum=0;
   int c=to_string(n).length();
    while(n>0){
        int l;
        l=n%10;
        sum=sum+pow(l,c);
        n=n/10;
       
    }
    if(dup==sum){
        cout<<"Armstrong Number";
    }
    else{
        cout<<"Not";
    }
}
int PrintDivisor(int n){
    int i;

    for(i=1;i<n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
        // else if(i>n){
        //     cout<<"Not"; 
        // }

    }
}
 int isDivisible(int n) {
        int s=0;
        int t=n;
        while(n>0){
            int l;
            l=n%10;
            s=s+l;
            n=n/10;
            
        }
        if(t%s==0){
            return 1;
        }
        else {
            return 0;
            
        }
    }

  int printGcd(int a,int b){
    while(a>0&&b>0){
        if(a>b){

    a=a%b;

   }
   else{
    b=b%a;
   }
   if(a==0){
    cout<<b;
   }
   else{
    cout<<a;
   }
  }
  }

int main(){
    
    // int a,b;
    // cin>>a>>b;
    int n;
    cin>>n;
//     cout<<counDigit(n)<<endl;
//   cout<<revNumber(n);
//   cout<<palindrome(n);
//   cout<<ArmstrongNum(n);
//   cout<<endl;
  cout<<PrintDivisor(n);
// cout<<isDivisible(n);
// cout<<checkPrime( n);
// cout<<isTwistedPrime(N);

// printGcd(a,b);

}