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
using lld = long double;


void solve() {
    lld h, _, da, dw;
    cin>>h>>_>>da>>dw;
    auto calc = [&](lld b) {
        lld top = b * dw * b * 0.5 + (h - b) * da * (h - (h - b) * 0.5);
        return top / (b * dw + (h - b) * da);
    };

    lld l=0, r=h;
    int count = 0;
    while (l + 0.0000000001 < r) {
        lld m = (l + r) / 2.0;
        if (calc(m) < m) r=m;
        else l=m; 
    }
    cout<<setprecision(15)<<l<<endl;
    //printf("%Lf\n", l);
}

int main() {
    // fastio
    int t = 1;
    while (t--) {
        solve();
    }
}