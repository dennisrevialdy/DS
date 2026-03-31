#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solve() {
    int k;
    if (scanf("%d", &k) != 1) return;

    char queue[1000][101];
    int head = 0;
    int tail = 0;

    for (int i = 0; i < k; i++) {
        scanf("%s", queue[tail++]);
    }

    while ((tail - head) > 1) {
        strcpy(queue[tail++], queue[head++]);
        strcpy(queue[tail++], queue[head++]);
        head++;
    }

    printf("%s\n", queue[head]);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        solve();
    }

    return 0;
}