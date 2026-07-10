// #include <bits/stdc++.h>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int>v={2,3,4,5,6};
//     vector<int>res;
//     while(v.size()!=1){
//      for(int i=1;i<v.size();i++){
//         res.push_back((v[i]+v[i-1])%10);
//      }
//     }
//     cout<<res<<endl;
// }

// int main(){
//     vector<int> v = {2, 3, 4, 5, 6};
    
//     while(v.size() != 1){
//         vector<int> temp;
//         for(int i = 1; i < v.size(); i++){
//             temp.push_back((v[i] + v[i-1]) % 10);
//         }
//         v = temp;  
        
       
//         for(int x : v){
//             cout << x << " ";
//         }
//         cout << endl;
//     }
    
//     cout << "Final result: " << v[0] << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
// int main(){
//     vector<int>v={4,3,5,2};
//     int c=0;
//     for(int i=0;i<v.size();i++){
//         for(int j=i+1;j<v.size();j++){
//             if((v[i] ^ v[j]) > (v[i] & v[j]))
//             c++;
//         }
//     }
//     cout<<c<<endl;
// }
int main(){
    int n;
    cin>>n;
    vector<int>v;
    while(n!=0){
        v.push_back(n%2);
        n=n/2;
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    
    return 0;
}