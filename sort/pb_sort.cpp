#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    cout << endl;
}

void solveInsertion(vector<int> arr, int N) {
    cout << "1" << endl;
    int m = arr.size();
    for (int i = 1; i <= N && i < m; i++) {
        printArray(arr);
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

    }
}

void solveBubble(vector<int> arr, int N) {
    cout << "2" << endl;
    int m = arr.size();
    for (int i = 0; i < N && i < m - 1; i++) {
        for (int j = m - 2; j >= i; j--) { 
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        printArray(arr);
    }
}


void solveSelection(vector<int> arr, int N) {
    cout << "3" << endl;
    int m = arr.size();
    for (int i = 0; i < N && i < m - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < m; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        swap(arr[i], arr[max_idx]);
        printArray(arr);
    }
}

int main() {
    int M, N;
    while (cin >> M >> N) {
        vector<int> scores(M);
        for (int i = 0; i < M; i++) {
            cin >> scores[i];
        }

        solveInsertion(scores, N);
        solveBubble(scores, N);
        solveSelection(scores, N);
    }
    return 0;
}
