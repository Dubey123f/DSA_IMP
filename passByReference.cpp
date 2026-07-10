#include<iostream>
using namespace std;
// pass by Reference
/*
In pass by reference original value  changes.
*/
void me(int &n){
    cout<<n<<endl;
    n=n+1;
    cout<<n<<endl;
    n=n+1;
    cout<<n<<endl;

}
int main(){
  int n=10;// original value
  me(n);
  cout<<n<<endl;// print(changed the original value)
  
}