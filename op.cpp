#include<iostream>
using namespace std;
// pass by value
/*
In pass by value original value does not change.
*/
void me(int n){
    cout<<n<<endl;
    n=n+1;
    cout<<n<<endl;
    n=n+1;
    cout<<n<<endl;

}
int main(){
  int n=10;// original value
  me(n);
  cout<<n<<endl;// print(original value)
  
}