#include <stdio.h>
#include <string.h>

int main() {
    char s[1000001];
    
    while (scanf("%s", s) == 1) {
        int n = strlen(s);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                putchar(s[(i + j) % n]);
            }
            if (i < n - 1) putchar(' ');
        }
        putchar('\n');
    }
    
    return 0;
}
