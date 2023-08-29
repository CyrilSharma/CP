// UNSOLVED
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            a[i] = c - '0';
        }
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            b[i] = c - '0';
        }
        // 0 0 1 0 0 1
        // 1 1 0 1 1 0
        // 0 0 1 0 0 0

        // a = 1 0 0 1 0 1
        // b = 0 1 1 0 0 1

    }
}