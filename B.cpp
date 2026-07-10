#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 0; i < n; i++){
        cout << "*";

        if(i == 0 || i == 2 || i == 4)
            cout << "***";
        else
            cout << "  *";

        cout << endl;
    }
}
