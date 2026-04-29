#include <iostream>
#include <string>

int main() {
   std::string name;
   int n = 0;
   while (getline(std::cin, name)) {
      n++;}
    std::cout<<"Hello World * " << n << std::endl;
    return 0;
}
