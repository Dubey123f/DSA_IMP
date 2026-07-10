/* PATTERN 1 
*
* *
* * *
* * * *
* * *
* *
*

*/
#include<iostream>
using namespace std;
void print1(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout<<"A";
        }
        cout<<endl;
    }
}
void print2(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<i;j++){
            cout<<"*";

        }
        cout<<endl;
    }
}
void print3(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void print4(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}
void print5(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void print6(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void print7(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i
        ;j++){
            cout<<" ";
        }
        for(j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(j=0;j<n-i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print8(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout<<" ";
        }
         for(j=0;j<((n*2-1)-(2*i));j++){
            cout<<"*";
        }
        for(j=0;j<=i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print9(int n){
    int i,j;
    for(i=0;i<2*n-1;i++){
        int s=i;
        if(s>n){
            s=2*n-i;
        }
        for(j=0;j<s;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
   print1();
   print2();
   print3();
      print4();
      int n;
      cin>>n;
      print5(n);
      print6(n);
      print7(n);
      print8(n);
      print9(n);
}