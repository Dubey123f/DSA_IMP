/*
STL in c++ is stand s for "standard template library"
*/ 
#include<bits/stdc++.h>
using namespace std;
void exepair(){
    pair<int,int>p={3,4};
//   pair<int,int>arr[]={3,{3,4}};
cout<<p.first<<"and" << p.second;
// cout<< arr[1].first;
}
void exeVec(){
    vector<int>v(2,4);
    v.insert(v.begin(),300);
    for(auto i:v){
        cout<<i<<" ";
    }
//     v.erase(v.begin()+2);
//  for(auto i:v){
//         cout<<i<<" ";
//     }
    cout<<endl;
    vector<int>copy(2,6);
v.insert(v.begin(),copy.begin(),copy.end());
 for(auto i:v){
        cout<<i<<endl;
    }
    cout<<"size is:"<<v.size()<<" ";
}
/*  *************** LIST ***************** */
// void listexe(){
//     list<int>ls;
//     ls.push_back(4);
//     ls.push_front(5);
//     cout<<ls.begin();
// }
// void priorityQueue(){
//     priority_queue<int>pq;
//     pq.push(5);
//     pq.push(3);
//     pq.push(8);
    
//     pq.pop();
//     cout<<pq.top();
    
// }
// void stackexe(){
//     map<int,int>st;
// st.insert(3,4);
// st.insert(2,3);
// st.insert(9,7);
// st.insert(0,9);
// for(auto it:st){
//     cout<<it<<"";
// }
    
// }
/* ************ SORTING TECHNIQUES IN C++ ************** */
void Sortin(){
    pair<int,int>a[]={{3,4},{4,5},{8,6},{9,5}};
    sort(a,a+4);
      for(auto lop:a){
 cout << "{" << lop.first << ", " << lop.second << "} ";
    }
    //for descending order
    sort(a, a+4, greater<pair<int,int>>());
    for(auto lop:a){
 cout << "{" << lop.first << ", " << lop.second << "} ";
    }
}
bool comp(pair<int ,int>p1 , pair<int,int>p2){
    if(p1.second<p2.second)
     return true;
    else if(p1.second==p2.second){
if(p1.first>p2.first){
    return true;
}
    }
    return false;
}
void SortMyway(){
    /*
    sort it accroding to icreasing second element
    if both second element is same then sort accroding to first but in decreasing order.
    */
    pair<int,int>a[]={{3,4},{4,5},{8,6},{9,5}};
sort(a,a+4,comp);
 for(auto lop:a){
 cout << "The sorted array is: {" << lop.first << ", " << lop.second << "} ";
    }
}
void BinaryR(){

    int a=6;
    int cnt=__builtin_popcount(a);
    // the biltin_popcount returns the number of set bit.
    cout<<"The result is:"<<cnt;
    long long n=12321123;
     // if the number is long long the __biltin_popcountll() returns the number of set bi
    int c=__builtin_popcountll(n);
        cout<<"The result is:"<<c;
}
void nextP(){
    string s="123";
    sort(s.begin(),s.end());
    do{
  cout<<s<<endl;
    } while(next_permutation(s.begin(),s.end()));
  

}
void maxandmin(){
    int a[5]={2,4,1,6,7};
    int maxi=*max_element(a,a+5);
    cout<<"The maximum element is:"<<maxi;

     int min=*min_element(a,a+5);
     cout<<"The minimum element is:"<<min;
}
int main(){
exepair();// craete pair

exeVec();// craete vector
// stackexe();
Sortin();// sorting the containers
SortMyway();// sort accroding to the question
BinaryR();// returs the binary bit
nextP();// returns the next permutation
maxandmin();// return s the max and min element.
}