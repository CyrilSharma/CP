#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;

struct DSU {
    vi parent, size;
    DSU(int n) {parent = vi(n,-1); size = vi(n,1);}
    int find(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b) {
        int r1 = find(a); int r2 = find(b);
        if (r1 == r2) return;
        if (size[r2] > size[r1]) swap(r1,r2);
        parent[r2] = r1; size[r1] += size[r2];
    }
};

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        DSU dsu(n);
        vector<tuple<int,int,int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char b; cin >> b;
                if (b=='1') dsu.merge(i,j);
                else edges.push_back({1,i,j});
            }
        }

        int ops = 0;
        set<int> used;
        for (int i = 0; i < edges.size(); i++) {
            if (dsu.size[dsu.find(0)] == n) break;
            auto [w, a, b] = edges[i];
            if (w == 1) {
                used.insert(a);
                ops++;
            }
            dsu.merge(a,b);
        }
        cout<<ops<<"\n";
        if (ops > 0) {
            for (auto num: used) cout << num+1 << " ";
            cout<<"\n";
        }
    }
}