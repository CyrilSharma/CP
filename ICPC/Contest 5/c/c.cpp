#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, a;
    cin >> n >> k;
    vector<int> fields(n);
    for (int i = 0; i < n; i++) {
        cin >> fields[i];
    }

    vector<pair<int,int>> dp(n);
    dp[0] = {1,1};
    for (int i = 1; i < n; i++) {
        auto [l,n] = dp[i-1];
        if (fields[i] != fields[i-1]) {
            dp[i] = {l+1,n+1};
        }
        else {
            dp[i] = {l,n+1};
        }
    }
    int minP = 1e9;
    for (int i = 0; i < n; i++) {
        auto [l, n] = dp[i];
        if (n < minP && l >= k) {
            minP = n;
        }
    }
    if (minP == 1e9) cout << "-1\n";
    else cout << minP << "\n";
}