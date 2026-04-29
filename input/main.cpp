#include <iostream>
#include <sstream>

int main() {
    std::string line;
    bool first = true;
    
    while (std::getline(std::cin, line)) {
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        long long product = 1;
        int num;
        while (iss >> num) {
            product *= num;
        }
        
        if (!first) {
            std::cout << std::endl;
        }
        first = false;
        
        for (long long i = 0; i < product; i++) {
            std::cout << "Hello World" << std::endl;
        }
    }
    
    return 0;
}