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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vi a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        q.push({a[i], i});
    }
    for (int i = 0; i < n;) {
        vector<pii> removed;
        for (int j = 0; j < k && i < n; i++, j++) {
            if (q.size() == 0) {
                cout<<"NO"<<endl;
                return ;
            }
            auto [val, color] = q.top(); q.pop();
            removed.push_back({val, color});
        }
        for (auto [val, color]: removed) {
            if (--val <= 0) continue;
            q.push({val, color});
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        solve();
    }
}