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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    fastio
    int t, s;
    cin >> t >> s;
    ll spidey = 0;
    ll overlap = 0;
    for (int x = 0; x < s; x++) {
        int maxT = max(t - x, 0);
        int maxS = min(2*(s-x), s-(x+1)/2);
        overlap += min(maxT, maxS);
        spidey += maxS;
    }
    overlap *= 4;
    spidey *= 4;

    // origin
    overlap += 1;
    spidey += 1;

    // reduce
    ll fac = gcd(overlap, spidey);
    overlap /= fac;
    spidey /= fac;
    if (spidey != 1) {
        cout<<overlap<<"/"<<spidey<<endl;
    } else {
        cout<<overlap<<endl;
    }
}
// loc is (x, y)
// suppose x < y.
// s = 1.5x + (y - x) => y = s - 0.5x
// s = 1.5y + (x - y) => y = 2(s - x)
// t = (y + x)
// fix x.
// for each x we can calc max y for t, and max y for s.
