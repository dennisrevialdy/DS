#include <iostream>

int main() {
    int num;
    while (std::cin >> num) {
        if(num ==0){
            break;
        }
        std::cout << num << " is the input number" << std::endl;
    }
    
    return 0;
}