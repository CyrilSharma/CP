#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        int zeros = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                zeros++;
            }
        }   

        using ll = long long;
        ll sum = 0;
        int count = zeros, i = 0;
        for (; i < n; i++) {
            if (a[i] == 0) continue;
            if (count >= m) break;
            sum += a[i];
            count++;
        }

        int mn = 1e9 + 1;
        for (; i < n; i++) {
            if (a[i] == 0) continue;
            mn = min(a[i], mn);
        }
        if (mn != 1e9 + 1) {
            sum += mn - 1;
        }

        if (count != m) {
            cout<<"Impossible\n";
        } else if (m == n) {
            cout<<"Richman\n";
        } else {
            cout<<sum<<"\n";
        }
    }
}