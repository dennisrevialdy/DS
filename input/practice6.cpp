#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    for(int i=0; i<t; i++) {
        int t2;
        std::cin >> t2;
        
        std::vector<std::string> names(t2);
        for(int j = 0; j < t2; j++) {
        std::cin >> names[j];
        }

        std::cout <<"Hello ";
        for(int j=0; j<t2;j++){
            if(j>0) std::cout << " ";
            std::cout << names[j];
        }
        std::cout<<std::endl;
    }
}
