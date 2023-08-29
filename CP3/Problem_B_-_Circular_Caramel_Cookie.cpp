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
using ld = long double;
ld eps = 1e-9;

ll calc(ld r) {
    ll count = 0;
    ll x = 1, y = floor(r);
    while (y > 0) {
        if (y*y + x*x > r*r) {
            y--;
        } else {
            count += y * 4;
            x++;
        }
    }
    return count;
}

void solve() {
    ll s; cin >> s;
    ld l=0, r=1e5;
    while (r - l > eps) {
        double m = (l + r) / 2;
        if (calc(m) <= s) l = m;
        else r = m;
    }
    cout<<fixed<<setprecision(15)<<r<<endl;
}

int main() {
    solve();
}