#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 0; i < n; i++){
        if(i == 0 || i == n-1)
            cout << " ****\n";
        else
            cout << "*\n";
    }
}
