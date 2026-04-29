#include <iostream>
#include <string>

int main() {
    while(1) {
        std::string name;

        for(int i = 0; i < 3; i++) {
            std::getline(std::cin, name);
            std::cout << "Hello " << name << " " << std::endl;
        }

        break; 
    }
    return 0;
}
