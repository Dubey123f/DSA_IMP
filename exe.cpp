#include <iostream>
#include <vector>

std::vector<int> finalstones(std::vector<int>& piles) {
    /*
    Write your logic here.
    Parameters:
        piles (std::vector<int>&): Vector of integers representing the array of stones
    Returns:
        void: Modify the vector in place
    */
    int n=piles.size();
    std::vector<int>temp;
    for(int i=0;i<n;i++){
        if(piles[i]>piles[i+1]){
 temp.push_back(piles[i]-piles[i+1]);
        }
       
    }
    return temp;
    
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> piles(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> piles[i];
    }
    
    finalstones(piles);
    
    for (int i = 0; i < N; ++i) {
        std::cout << piles[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}