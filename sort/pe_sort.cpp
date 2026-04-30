#include <iostream>
int main(){
    int m, n, k;
    while(std::cin >> m >> n){
        std::cin >> k;
        if(k < m || k > n){
            std::cout << -1 << std::endl;
            continue;
        }
        int low = m, high = n, count = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            count++;
            if(mid == k){
                break;
            } else if(mid < k){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        std::cout << count << std::endl;
    }
}
