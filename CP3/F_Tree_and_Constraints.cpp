#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int timer = 0;
    int L = ceil(log2(N + 1));
    vector<int> tin(N + 1), tout(N + 1);
    vector<vector<int>> up(N + 1, vector<int>(L + 1));
    function<void(int,int)> compute_lca;
    compute_lca = [&](int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= L; i++) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (int nbr: graph[v]) {
            if (nbr == p) continue;
            compute_lca(nbr, v);
        }
        tout[v] = ++timer;
    };
    compute_lca(1, 1);

    auto isAncestor = [&](int u, int v) {
        return tin[u] <= tin[v] &&
            tout[u] >= tout[v];
    };

    auto LCA = [&](int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        }
        if (isAncestor(v, u)) {
            return v;
        }
        for (int i = L; i >= 0; --i) {
            if (!isAncestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    };

    int M; cin >> M;
    vector<pair<int,int>> constraints(M);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        constraints[i] = {a, b};
    }
    
    long long invalid = 0;
    set<int> include;
    function<void(int,int)> dfs;
    dfs = [&](int i, int count) {
        if (i == M) {
            if (count == 0) return;
            assert(N - 1 - include.size() >= 0);
            long long del = (1LL << (N - 1 - include.size()));
            invalid += (count%2) ? del : -del;
            return;
        }
        dfs(i + 1, count);
        vector<int> changes;
        auto [a, b] = constraints[i];
        int anc = LCA(a, b);
        for (int j = 0; j < 2; j++) {
            int cur = j ? a : b;
            while (cur != anc) {
                if (!include.count(cur)) {
                    include.insert(cur);
                    changes.push_back(cur);
                }
                cur = up[cur][0];
            }
        }
        dfs(i + 1, count + 1);
        for (int change: changes) {
            include.erase(change);
        }
    };
    dfs(0, 0);
    long long ans = (1LL << (N - 1)) - invalid;
    cout<<ans<<endl;
}