#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        char s[85];
        scanf("%s", s);
        
        int total = 0;
        int consecutive = 0;
        
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == 'O') {
                consecutive++;
                total += consecutive;
            } else {
                consecutive = 0;
            }
        }
        
        printf("%d\n", total);
    }
    
    return 0;
}
