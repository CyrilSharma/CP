#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    long long combos = 1;
    int rounds = 0;
    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        combos *= q;
        for (; combos%2 == 0; rounds++) {
            combos = combos/2;
        }
        combos = 1;
    }
    cout << rounds;
}