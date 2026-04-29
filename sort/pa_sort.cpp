#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string_view>

using namespace std;

void solve() {
    string s;
    while (cin >> s) {
        int n = s.length();
        bool foundAny = false;

        for (int k = 1; k < n; k++) {
            if (n % k == 0) {
                vector<string_view> chunks;
                
                for (int i = 0; i < n; i += k) {
                    chunks.push_back(string_view(s.data() + i, k));
                }

                vector<string_view> original = chunks;
                sort(chunks.begin(), chunks.end());

                if (chunks != original) {
                    foundAny = true;
                    for (auto chunk : chunks) {
                        cout << chunk;
                    }
                    cout << "\n";
                }
            }
        }

        if (!foundAny) {
            cout << "orz\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
