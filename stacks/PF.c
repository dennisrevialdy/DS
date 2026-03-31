#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long m, n;
    while (scanf("%lld %lld", &m, &n) == 2) {
        long long power_of_two = 1;

        for (int i = 0; i < n; i++) {
            power_of_two *= 2;
        }

        long long result = m * (power_of_two - 1);
        printf("%lld\n", result);
    }
    return 0;
}