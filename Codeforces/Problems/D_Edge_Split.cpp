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

struct DSU {
    int nc; vi parent, size;
    DSU(int n) {parent=vi(n,-1); size=vi(n,1); nc=n;}
    int find(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b) {
        int r1 = find(a); int r2 = find(b);
        if (r1 == r2) return;
        if (size[r2] > size[r1]) swap(r1,r2);
        parent[r2] = r1; size[r1] += size[r2];
        nc--;
    }
};

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            edges[i] = {u-1, v-1};
        }  

        vi bedges, ans(m);
        DSU ds(n);
        for (int i = 0; i < m; i++) {
            auto [u, v] = edges[i];
            if (ds.find(u) != ds.find(v)) {
                ans[i] = 1;
                ds.merge(u,v);
            } else {
                bedges.push_back(i);
            }
        }

        auto hasCycle = [&]() {
            if (bedges.size() < 3) return false;
            map<int,int> has;
            for (int i = 1; i <= 2; i++) {
                auto [f, s] = edges[bedges[i]];
                has[f]++, has[s]++;
            }
            return has.size()==3;
        };

        if (hasCycle()) {
            int u1 = edges[bedges[0]].first;
            for (int i = 0; i < m; i++) {
                auto [f, s] = edges[i];
                if (f==u1 || s==u1) {
                    ans[i] = 0;
                    ans[bedges[0]] = 1;
                    break;
                }
            }
        }
        for (auto &a: ans) cout<<a;
        cout<<endl;
    }
}
/**
 * @brief Can be actually solved with randomization or
 * You could figure out the proof and solve it by disconnecting edge of greatest depth.
 * Idrk why that works though.
 */