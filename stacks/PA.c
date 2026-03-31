#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

long long calculate(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

void print_postfix(char tokens[110][20], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s%s", tokens[i], (i == count - 1 ? "" : " "));
    }
    printf("\n");
}

int main() {
    char input[110];
    if (scanf("%s", input) != 1) return 0;

    char stack[110];
    int top = -1;
    char postfix[110][20];
    int p_idx = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            postfix[p_idx][0] = input[i];
            postfix[p_idx][1] = '\0';
            p_idx++;
        }
        else if (input[i] == '(') {
            stack[++top] = '(';
        }
        else if (input[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[p_idx][0] = stack[top--];
                postfix[p_idx][1] = '\0';
                p_idx++;
            }
            top--;
        }
        else {
            while (top >= 0 && precedence(stack[top]) >= precedence(input[i])) {
                postfix[p_idx][0] = stack[top--];
                postfix[p_idx][1] = '\0';
                p_idx++;
            }
            stack[++top] = input[i];
        }
    }
    while (top >= 0) {
        postfix[p_idx][0] = stack[top--];
        postfix[p_idx][1] = '\0';
        p_idx++;
    }

    print_postfix(postfix, p_idx);

    while (p_idx > 1) {
        int op_pos = -1;
        for (int i = 0; i < p_idx; i++) {
            if (strlen(postfix[i]) == 1 && (postfix[i][0] == '+' || postfix[i][0] == '-' ||
                postfix[i][0] == '*' || postfix[i][0] == '/')) {
                op_pos = i;
                break;
            }
        }

        long long a = atoll(postfix[op_pos - 2]);
        long long b = atoll(postfix[op_pos - 1]);
        long long res = calculate(a, b, postfix[op_pos][0]);

        sprintf(postfix[op_pos - 2], "%lld", res);

        for (int i = op_pos - 1; i < p_idx - 2; i++) {
            strcpy(postfix[i], postfix[i + 2]);
        }
        p_idx -= 2;

        if (p_idx > 1) {
            print_postfix(postfix, p_idx);
        }
        else {
            printf("%s\n", postfix[0]);
        }
    }

    return 0;
}