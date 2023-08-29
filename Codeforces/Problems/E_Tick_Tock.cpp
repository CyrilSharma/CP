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

ll MOD = 1e9+7;
ll add(ll a, ll b, ll m = MOD) {
    a+=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll mult(ll a, ll b, ll m = MOD) {
    if(abs(a)>=m) a%=m;
    if(abs(b)>=m) b%=m;
    a*=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll pw(ll a, ll b, ll m = MOD) {
    if(abs(a)>=m) a%=m;
    if(a==0 && b==0) return 0; // value of 0^0
    ll r=1;
    for(; b; b >>= 1) {
        if(b&1) r=mult(r,a,m);
        a=mult(a,a,m);
    }
    return r;
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vvi grid(n, vi(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        // build graph.
        int nempty = 0;
        vector<vector<pii>> adj(n);
        for (int j = 0; j < m; j++) {
            int last = -1;
            bool empty = true;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == -1) continue;
                if (last != -1) {
                    adj[last].push_back({i, add(grid[i][j],-grid[last][j],h)});
                    adj[i].push_back({last, add(grid[last][j],-grid[i][j],h)});
                }
                last = i;
                empty = false;
            }
            nempty += empty;
        }

        // connected components.
        vi ans(n,-1);
        bool ok = true;
        function<void(int,int)> dfs = [&](int node, int dist) {
            ans[node] = dist;
            for (auto [nb, nbd]: adj[node]) {
                if (ans[nb] == -1)
                    dfs(nb, add(dist, nbd, h));
                else if (add(dist, nbd, h) != ans[nb]) {
                    ok = false; return;
                }
            }
        };

        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) continue;
            cc++;
            dfs(i, 0);
        }
        cout<<pw(h, cc - 1 + nempty) * ok<<endl;
    }
}
/**
 * @brief beware of returns from recursive functions.
 * proving irregularity required tracking total dist, 
 * so just remember to actually think about your criteria.
 */