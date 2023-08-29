#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi b(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        vi dp(n+1); dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i + b[i] <= n && dp[i-1]) dp[b[i]+i] = 1;
            if (i - b[i] - 1 >= 0 && dp[i-b[i]-1]) dp[i] = 1;
        }
        cout << (dp[n] ? "YES" : "NO") << endl;
    }
}