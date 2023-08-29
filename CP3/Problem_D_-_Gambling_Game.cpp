#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = __int128;
using vll = vector<ll>;
using vvll = vector<vll>;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int m, n, p;
    cin >> m >> n >> p; 
    vvll dp(n+1, vll(p+1));
    dp[0][0] = 1;
    for (int j = 0; j < p; j++) {
        for (int i = 0; i <= n-1; i++) {
            dp[i][j+1] += dp[i][j] * max((m-j) - 2 * (n-i), 0);
            dp[i+1][j+1] += dp[i][j] * 2 * (n-i);
        }
    }
    ll top = dp[n][p];
    ll bottom = 1;
    for (int i = 0; i < p; i++) {
        bottom *= (m-i);
    }

    ll factor = gcd(top, bottom);
    top /= factor, bottom /= factor;
    print(top);
    cout<<"/";
    print(bottom);
    cout<<endl;
}