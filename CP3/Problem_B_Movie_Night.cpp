#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> parent(n + 1);
    vector<vector<int>> child(n + 1);
    for (int x = 1; x <= n; x++) {
        int y; cin >> y;
        parent[x] = y;
        child[y].push_back(x);
    }

    vector<int> order;
    vector<int> done(n + 1);
    function<void(int)> dfs1;
    dfs1 = [&](int node) {
        assert(node >= 1 && node <= n);
        done[node] = 1;
        auto p = parent[node];
        if (!done[p] && p != 0) {
            dfs1(p);
        }
        order.push_back(node);
    };

    for (int i = 1; i <= n; i++) {
        if (done[i]) continue;
        dfs1(i);
    }

    int cindex = 1;
    vector<int> comp(n + 1);
    vector<int> in(n + 1);
    vector<vector<int>> out(n + 1);
    done.assign(n + 1, 0);
    function<void(int)> dfs2;
    dfs2 = [&](int node) {
        assert(node >= 1 && node <= n);
        done[node] = 1;
        comp[node] = cindex;
        for (auto c: child[node]) {
            if (done[c]) continue;
            dfs2(c);
        }
    };

    reverse(order.begin(), order.end());
    for (int i: order) {
        if (done[i]) continue;
        dfs2(i);
        cindex++;
    }

    for (int i = 1; i <= n; i++) {
        auto p = parent[i];
        if (p == 0) continue;
        if (comp[p] != comp[i]) {
            in[comp[i]] = comp[p];
            out[comp[p]].push_back(comp[i]);
        }
    }

    using ll = long long;
    ll MOD = 1e9 + 7;
    function<ll(int)> dfs3;
    dfs3 = [&](int node) {
        assert(node >= 1 && node < cindex);
        ll used = 1;
        for (auto c: out[node]) {
            used = (used * dfs3(c)) % MOD;
        }
        return (used + 1) % MOD;
    };

    ll answer = 1;
    for (int i = 1; i < cindex; i++) {
        if (in[i] == 0) {
            answer = (answer * dfs3(i)) % MOD;
        }
    }
    cout << (answer - 1 + MOD) % MOD << endl;
}