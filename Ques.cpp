// Online C++ compiler to run C++ program online
    #include <iostream>
    #include <bitset>
    #include <string>
using namespace std;
    int main() {
        int decimal_num = 123;
        int n;
        cout << "Enter a number of bit: ";
        cin >> n;
        // Convert to an 8-bit binary string
   string binary_str = bitset<n>(decimal_num).to_string(); 
        cout << "Binary representation of " << decimal_num << ": " << binary_str << endl;
        return 0;
    }