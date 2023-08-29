#include <bits/stdc++.h>
using namespace std;

// DSU with rollback -> no path compression.
struct DSU {
    stack<tuple<int,int,int,int>> hist;
    using vi = vector<int>;
    vi parent, size;
    int nc;
    DSU(int n) {
        parent.assign(n, -1); 
        size.assign(n, 1);
        nc = n;
    }
    int find(int v) {
        if (parent[v] == -1) return v;
        return find(parent[v]);
    }
    void add(int a, int b) {
        int r1 = find(a), r2 = find(b);
        hist.push({r1, parent[r1], size[r1], nc});
        hist.push({r2, parent[r2], size[r2], nc});
        if (r1 == r2) return;
        if (size[r2] > size[r1]) swap(r1,r2);
        parent[r2] = r1; size[r1] += size[r2];
        nc--;
    }
    void erase() {
        for (int i = 0; i < 2; i++) {
            assert(!hist.empty());
            auto [u, p, s, n] = hist.top(); hist.pop();
            parent[u] = p;
            size[u] = s;
            nc = n;
        }
    }
};

int main() {
    //freopen("connect.in", "r" , stdin);
    //freopen("connect.out", "w" , stdout);
    ifstream infile("connect.in"); 
    ofstream outfile("connect.out"); 

    int N, K;
    infile >> N >> K;
    if (K == 0) return 0;
    vector<vector<pair<int,int>>> tree(4 * K + 100);
    function<void(int,int,int,int,int,pair<int,int>)> add;
    add = [&](int i, int l, int r, int L, int R, pair<int,int> edge) {
        if (L > r || R < l) return;
        if (L <= l && r <= R) {
            tree[i].push_back(edge);
            return;
        }
        int m = (l + r) / 2;
        add(2 * i + 1, l, m, L, R, edge);
        add(2 * i + 2, m + 1, r, L, R, edge);
    };

    DSU D(N);
    vector<int> queries(K);
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
            assert(l < K);
            if (queries[l] == 1) {
                outfile<<D.nc<<endl;
            }
        }
        for (int j = 0; j < tree[i].size(); j++) {
            D.erase();
        }
    };
    
    map<pair<int,int>,int> occur;
    for (int i = 0; i < K; i++) {
        char c; infile >> c;
        if (c == '+') {
            int u, v;
            infile >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            occur[{u, v}] = i;
        } else if (c == '-') {
            int u, v;
            infile >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            add(0, 0, K - 1, occur[{u, v}], i - 1, {u, v});
            occur.erase({u, v});
        } else if (c == '?') {
            queries[i] = 1;
        }
    }
    for (auto [edge, i] : occur) {
        add(0, 0, K - 1, i, K - 1, edge);
    }
    dfs(0, 0, K - 1);
}