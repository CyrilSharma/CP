#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using triple = tuple<ll,ll,ll>;
triple euclid(ll a, ll b, ll x, ll y) {
    if (b == 0) return {a, 1, 0};
    auto [d, x1, y1] = euclid(b, a%b, x, y);
    ll nx = y1;
    ll ny = x1 - y1 * (a / b);
    return {d, nx, ny};
}

int main() {
    int MOD = 998244353;
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<int> arr(n);
        int nzeros = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) nzeros++;
        }
        int nwrong = 0;
        for (int i = 0; i < nzeros; i++) {
            if (arr[i] == 1) nwrong++;
        }
        int nright = nzeros - nwrong;
        ll tot = ((n * (n - 1)) / 2) % MOD;
        auto [d, x, y] = euclid(tot, MOD, 0, 0);
        ll invtot = (x % MOD + MOD) % MOD;
        vector<ll> dp(nzeros+1);
        for (int i = nzeros; i > nright; i--) {
            ll sqr = ((ll)(nzeros-i+1) * (ll)(nzeros-i+1)) % MOD;
            ll p = (sqr * invtot) % MOD;
            auto [d2, x2, y2] = euclid(p, MOD, 0, 0);
            ll invp = (x2 % MOD + MOD) % MOD;
            dp[i-1] = (dp[i] + invp) % MOD;
        }
        cout<<dp[nright]<<"\n";
    }
}
/**
 * This was a new type of problem, the core idea is use markovian relationships!
 * You made a good first guess as to the approach, I'd say you did as well as you could've.
 */