#include <bits/stdc++.h>
using namespace std;

struct DSU {
    using vi = vector<int>;
    stack<tuple<int,int,int,int>> hist;
    vi parent, size;
    int nc;

    DSU(int n) {
        parent = vi(n,-1);
        size = vi(n,1); 
        nc = n;
    }
    int find(int v) {
        if (parent[v] == -1) return v;
        return find(parent[v]);
    }
    void add(int a, int b) {
        int r1 = find(a); int r2 = find(b);
        hist.push({r1, parent[r1], size[r1], nc});
        hist.push({r2, parent[r2], size[r2], nc});
        if (r1 == r2) return;
        if (size[r2] > size[r1]) swap(r1,r2);
        parent[r2] = r1; size[r1] += size[r2];
        nc--;
    }
    void pop() {
        for (int i = 0; i < 2; i++) {
            auto [u, p, s, c] = hist.top(); hist.pop();
            parent[u] = p;
            size[u] = s;
            nc = c;
        }
    }
};

int main() {
    freopen("disconnected.in", "r", stdin);
    freopen("disconnected.out", "w", stdout);

    int n, m; 
    cin >> n >> m;
    const int Q = 1e5 + 5;
    vector<vector<pair<int,int>>> tree(4 * Q);
    function<void(int,int,int,int,int,pair<int,int>)> add;
    add = [&](int i, int l, int r, int L, int R, pair<int,int> edge) {
        if (l > r) return;
        if (L > r || R < l) return;
        if (L <= l && r <= R) {
            tree[i].push_back(edge);
            return;
        }
        int m = (l + r) / 2;
        add(2 * i + 1, l, m, L, R, edge);
        add(2 * i + 2, m + 1, r, L, R, edge);
    };

    
    vector<pair<int,int>> edges(m);
    map<pair<int,int>,int> occur;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        occur[{--u, --v}] = 0;
        edges[i] = {u, v};
    }

    int k; cin >> k;
    vector<int> queries(Q);
    for (int i = 1; i <= k; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            int index; cin >> index;
            auto [u, v] = edges[index - 1];
            add(0, 0, Q - 1, occur[{u, v}], i - 1, {u, v});
            occur[{u, v}] = i + 1;
        }
        queries[i] = 1;
    }

    for (auto &[edge, i]: occur) {
        add(0, 0, Q - 1, i, Q - 1, edge);
    }

    DSU D(n);
    function<void(int,int,int)> dfs;
    dfs = [&](int i, int l, int r) {
        for (auto &edge: tree[i]) {
            D.add(edge.first, edge.second);
        }
        int m = (l + r) / 2;
        if (l < r) {
            dfs(2 * i + 1, l, m);
            dfs(2 * i + 2, m + 1, r);
        } else {
            if (queries[l]) {
                cout<<(D.nc == 1 ? "Connected" : "Disconnected")<<endl;
            }
        }
        for (int j = 0; j < tree[i].size(); j++) {
            D.pop();
        }
    };
    dfs(0, 0, Q - 1);
}