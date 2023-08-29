#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int U, V; cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    vector<int> order, used(N);
    vector<vector<int>> TR(N);
    function<void(int,int)> dfs1;
    dfs1 = [&](int node, int parent) {
        used[node] = 1;
        for (int nbr: adj[node]) {
            if (nbr == parent) continue;
            TR[nbr].push_back(node);
            if (used[nbr]) continue;
            dfs1(nbr, node);
        }
    };
    dfs1(0,0);

    int count = 0;
    used.assign(N, 0);
    function<void(int)> dfs2;
    dfs2 = [&](int node) {
        count++;
        used[node] = 1;
        for (int nbr: TR[node]) {
            if (used[nbr]) continue;
            dfs2(nbr);
        }
    };

    dfs2(0);
    cout<<count<<endl;
}