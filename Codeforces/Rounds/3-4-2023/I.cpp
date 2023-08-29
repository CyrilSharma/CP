#include <bits/stdc++.h>
#include <atcoder/maxflow>

using namespace std;
using namespace atcoder;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int s = 0, t = n + 2*m + 1;
    int K = n + 2*m + 2;
    mf_graph<int> g(n + 2*m + 3);
    g.add_edge(s, K, k);
    for (int i = 1; i <= n; i++) {
        g.add_edge(s, i, 1);
        g.add_edge(K, i, 1);
    }
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        for (int j = 1; j <= t; j++) {
            int mij; cin >> mij;
            g.add_edge(i, n+mij, 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        g.add_edge(n+i, n+m+i, 1);
        g.add_edge(n+m+i, t, 1);
    }
    cout<<g.flow(s, t)<<endl;
}