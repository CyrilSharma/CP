#include <bits/stdc++.h>
using namespace std;
int main() {
    int mod = 1e9+7;
    int n; cin >> n;
    vector<long long> totals(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i < 2) totals[i] = a;
        else {
            totals[i] = (a * (totals[i-1] + totals[i-2]) % mod) % mod;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << totals[i] << " ";
    }
}