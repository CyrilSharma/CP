#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int l = dp[i-1];
        if (a[i] > l) {
            dp[i] = l+1;
        }
        else {
            dp[i] = a[i];
        }
    }
    int best = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > best) {
            best = dp[i];
        }
    }
    cout << best << "\n";
}