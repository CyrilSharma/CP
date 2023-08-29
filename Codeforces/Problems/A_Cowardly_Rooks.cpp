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
        int n, m;
        cin >> n >> m;
        int rows=n; int cols=n;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            cols--; rows--;
        }
        if (rows>0 || cols>0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}