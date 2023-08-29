#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
    //fastio
    int t; cin >> t;
    while (t--) {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        if (s < k*b || s > (k*b + n*(k-1))) {
            cout<<"-1\n"; 
            continue;
        }
        s -= k*b;
        for (int i = 0; i < n; i++) {
            if (i == 0) printf("%lld ", k*b + min(s, k-1));
            else printf("%lld ", min(s, k-1));
            s -= min(s, k-1);
        }
        cout<<"\n";
    }
}
/**
 * don't mix printf and cout if using fastio,
 */