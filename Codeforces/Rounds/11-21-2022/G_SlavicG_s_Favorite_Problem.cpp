#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i = 0; i < n-1; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        function<set<int>(int,int)> search;
        search = [&](int src, int blk) {
            queue<pair<int,int>> q;
            set<int> s;
            vector<int> visited(n+1); 
            visited[src] = 1;
            q.push({0,src});
            while(!q.empty()) {
                auto [x, node] = q.front(); q.pop();
                for(auto tmp: adj[node]) {
                    auto [nbrd, nbr] = tmp;
                    if (visited[nbr]) continue;
                    visited[nbr] = 1;
                    if (nbr == blk) continue;
                    int nw = x^nbrd;
                    s.insert(nw);
                    q.push({nw, nbr});
                }
            }
            return s;
        };
        bool found = false;
        auto adist = search(a, b); adist.insert(0);
        auto bdist = search(b, -1);
        for (auto dist: adist) {
            if (bdist.count(dist) == 1) {
                cout<<"YES\n";
                found = true;
                break;
            }
        }
        if (!found) cout<<"NO\n";
    }
}
/**
 * Ensure you're building the adjacency list correctly everytime.
 * 
 * 
 */