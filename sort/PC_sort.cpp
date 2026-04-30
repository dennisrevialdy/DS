#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    while(std::cin >> n){
        if(n==0) break;
        
        std::vector<int> s(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> s[i];
        }
        std::sort(s.begin(), s.end());

        int group = n / 2;
        std::cout << group << std::endl;
        for(int i =0; i < group; ++i){
            if(i > 0) std::cout << " ";
            std::cout << s[i]+s[n-1-i] << std::endl;
        }
        std::cout << std::endl;
    }
}
