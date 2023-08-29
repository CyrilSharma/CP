#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        for (int i = 1; i < n; i++) {
            int p; cin >> p;
            adj[p].push_back(i+1);
        }
        vector<ll> scores(n+1);
        for (int i = 0; i < n; i++) {
            cin >> scores[i+1];
        }

        function<pair<ll,ll>(int,ll)> dfs;
        dfs = [&](int node, ll count) -> pair<ll,ll> {
            int nchild = adj[node].size();
            if (nchild == 0) {
                return {scores[node] * count, scores[node]};
            }
            ll div = count / nchild;
            ll rem = count % nchild;
            ll tot = scores[node] * count;
            vector<ll> maxes;
            for (int child: adj[node]) {
                auto [val, nbest] = dfs(child, div);
                tot += val;
                maxes.push_back(nbest);
            }
            sort(maxes.begin(), maxes.end());
            while (rem--) tot += maxes.back(), maxes.pop_back();
            return {tot, maxes.back() + scores[node]};
        };
        ll ans = dfs(1, k).first;
        printf("%lld\n", ans);
    }
}