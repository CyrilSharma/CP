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

#define sz (int)(2*1e5 + 1)
vvi adj(sz, vi());
int depth[sz];
int tsize[sz];
int prune(int node, int parent, int d, int mx_depth) {
    if (d == (mx_depth) || tsize[node] == 0) {
        int save = tsize[node];
        tsize[node] = 0;
        return save;
    }
    int total = 0;
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (child == parent) continue;
        total += prune(child, node, d+1, mx_depth);
    }
    tsize[node] -= total;
    return total;
}

int cnt = 0;
void dfs(int node, int parent) {
    tsize[node] = 1;
    int lchild = -1, rchild = -1;
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (child == parent) continue;
        if (lchild == -1) lchild = child;
        else rchild = child;
        dfs(child, node);
    }

    // base case;
    if (lchild == -1 && rchild == -1) {
        depth[node] = 1;
        return;
    }

    int l = lchild != -1 ? depth[lchild] : 0;
    int r = rchild != -1 ? depth[rchild] : 0;
    // if unbalanced, balance.
    if (l - 1 > r) {
        cnt += prune(lchild, node, 0, r + 1);
        l = r + 1;
    } else if (r - 1 > l) {
        cnt += prune(rchild, node, 0, l + 1);
        r = l + 1;
    }
    // update size of the tree.
    if (lchild != -1) tsize[node] += tsize[lchild];
    if (rchild != -1) tsize[node] += tsize[rchild];
    depth[node] = max(l + 1, r + 1);
    return;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout<<cnt<<endl;
}