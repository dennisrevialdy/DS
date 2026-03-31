#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005


int left_heap[MAXN];
int left_size = 0;


int right_heap[MAXN];
int right_size = 0;


void left_push(int val) {
    int i = ++left_size;
    left_heap[i] = val;
    while (i > 1 && left_heap[i] > left_heap[i / 2]) {
        int tmp = left_heap[i];
        left_heap[i] = left_heap[i / 2];
        left_heap[i / 2] = tmp;
        i /= 2;
    }
}

int left_pop() {
    int top = left_heap[1];
    left_heap[1] = left_heap[left_size--];
    int i = 1;
    while (1) {
        int largest = i;
        int l = 2 * i, r = 2 * i + 1;
        if (l <= left_size && left_heap[l] > left_heap[largest]) largest = l;
        if (r <= left_size && left_heap[r] > left_heap[largest]) largest = r;
        if (largest == i) break;
        int tmp = left_heap[i];
        left_heap[i] = left_heap[largest];
        left_heap[largest] = tmp;
        i = largest;
    }
    return top;
}


void right_push(int val) {
    int i = ++right_size;
    right_heap[i] = val;
    
    while (i > 1 && right_heap[i] < right_heap[i / 2]) {
        int tmp = right_heap[i];
        right_heap[i] = right_heap[i / 2];
        right_heap[i / 2] = tmp;
        i /= 2;
    }
}

int right_pop() {
    int top = right_heap[1];
    right_heap[1] = right_heap[right_size--];
    int i = 1;
    while (1) {
        int smallest = i;
        int l = 2 * i, r = 2 * i + 1;
        if (l <= right_size && right_heap[l] < right_heap[smallest]) smallest = l;
        if (r <= right_size && right_heap[r] < right_heap[smallest]) smallest = r;
        if (smallest == i) break;
        int tmp = right_heap[i];
        right_heap[i] = right_heap[smallest];
        right_heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}


void insert(int val) {
    if (left_size == 0 || val <= left_heap[1])
        left_push(val);
    else
        right_push(val);

    if (left_size > right_size + 1)
        right_push(left_pop());
    else if (right_size > left_size)
        left_push(right_pop());
}

long long get_median() {
    if (left_size == right_size)
        return (long long)(left_heap[1] + right_heap[1]) / 2;
    else
        return left_heap[1];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);

        left_size = 0;
        right_size = 0;

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            insert(x);
            sum += get_median();
        }
        printf("%lld\n", sum);
    }
    return 0;
}
