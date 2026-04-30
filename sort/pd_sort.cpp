#include <iostream>
#include <vector>
#include <algorithm>

struct mosquito{
    int no, decible;
    float weight, speed;
};

int main(){
    int n;
    while(std::cin >> n){
        if(n == 0) break;
        std::vector<mosquito> no(n);
        for(int i = 0; i < n; i++){
            std::cin >> no[i].no >> no[i].weight >> no[i].speed >> no[i].decible;
        }
        std::sort(no.begin(), no.end(), [](const mosquito &a, const mosquito &b){
            if(a.decible != b.decible) return a.decible > b.decible;
            if(a.speed != b.speed) return a.speed > b.speed;
            if(a.weight != b.weight) return a.weight < b.weight;
            return a.no < b.no;
        });
        for(int i = 0; i < n; i++){
            std::cout << no[i].no <<std::endl;
        }
    }
}
