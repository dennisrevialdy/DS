#include <iostream>

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        int num;
        std::cin >> num;
        std::cout << num << " is the input number" << std::endl;
    }
    
    return 0;
}