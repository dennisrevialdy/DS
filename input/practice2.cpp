#include <iostream>

int main() {
    int n;
    while (std::cin >> n) {
        if(n == 0) {
            break;
        }
        std::cout <<  "Hello World" << std::endl;
    }
    
    return 0;
}
