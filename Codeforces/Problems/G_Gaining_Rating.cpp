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

ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vll a(n);
    for (auto &ai: a) cin >> ai;
    sort(a.begin(), a.end());

    vll start(n), end(n);
    start[0]=a[0], end[0]=a[0]+1;
    for (int i = 1; i < n; i++) {
        if (end[i-1] >= a[i]) {
            start[i]=start[i-1];
            end[i]=end[i-1]+1;
        } else {
            start[i]=(a[i]-i); 
            end[i]=(a[i]+1);
        }
    } 

    bool ok = true;
    ll count=0;
    while (x < y) {
        ll p = upper_bound(start.begin(), start.end(), x) - start.begin();
        ll m = n - p;
        if (x + p >= y) {
            cout << count + y - x << endl;
            return;
        }
        if (p <= m) {
            cout<<-1<<endl;
            return;
        }
        ll k = ceil(y-x-p,p-m);
        if (p < n) k = min(k, ceil(start[p] - x, p - m));
        count += k * n;
        x += k * (p - m);
    }
}

int main() {
    fastio
    int t; cin >> t; 
    while (t--) {
        solve();
    }
}