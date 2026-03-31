#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 200005

int undone[MAX_TASKS];
int processing[MAX_TASKS];

void solve(int n) {
    int u_head = 0, u_tail = 0;
    int p_head = 0, p_tail = 0;
    int val;
    char c;

    // Read tasks for the current line
    while (scanf("%d%c", &val, &c) == 2) {
        undone[u_tail++] = val;
        if (c == '\n' || c == '\r') break;
    }

    int current_limit = n;

    while (u_head < u_tail) {
        int p_size = p_tail - p_head;

        if (p_size < current_limit) {
            processing[p_tail++] = undone[u_head++];
        }
        else {
            int first_in_proc = processing[p_head++];
            int upcoming_task = undone[u_head++];

            if (upcoming_task > first_in_proc) {
                processing[p_tail++] = upcoming_task;
                undone[u_tail++] = first_in_proc;
            }
            else {
                processing[p_tail++] = first_in_proc;
                undone[u_tail++] = upcoming_task;
            }
            current_limit++;
        }
    }

   
    for (int i = p_head; i < p_tail; i++) {
        printf("%d%s", processing[i], (i == p_tail - 1 ? "" : " "));
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        solve(n);
    }
    return 0;
}