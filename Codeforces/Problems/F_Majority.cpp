// Attempt after Dec 2.
#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

int main() {
    fastio
    int n, m;
    cin >> n >> m;
    // # with length i, electrical prefix j.
    vvll dp(n+1, vll(n+1));
    vll triangle(n);
    ll ptwo = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = ptwo;
        ll sum = ptwo;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[j][j] * (triangle[max(i-2*j, 0)] + 1)) % m;
            sum = (sum + dp[i][j]) % m;
        }
        ptwo = (ptwo * 2) % m;
        dp[i][i] = ((ptwo - sum) % m + m) % m;
        // The triangle sums are unintuitive to me for some reason.
        ll acc = 0;
        for (int j = 1; i + j < n; j++) {
            triangle[i+j] = (triangle[i+j] + acc) % m; 
            acc = (acc + dp[i][j]) % m;
        }
    }
    cout<<dp[n][n]<<endl;
}