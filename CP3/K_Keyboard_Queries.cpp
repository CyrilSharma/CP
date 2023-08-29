#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
ll MOD = 1e9 + 7;
ll BASE = 1e5 + 3;
ll add(ll a, ll b, ll m = MOD) {
    a+=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll mult(ll a, ll b, ll m = MOD) {
    if(abs(a)>=m) a%=m;
    if(abs(b)>=m) b%=m;
    a*=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll pw(ll a, ll b, ll m = MOD) {
    assert(b >= 0);  // can return 0 if desired
    if(abs(a)>=m) a%=m;
    if(a==0 && b==0) return 1; // value of 0^0
    ll r=1;
    for(; b; b >>= 1) {
        if(b&1) r=mult(r,a,m);
        a=mult(a,a,m);
    }
    return r;
}

ll inverse(ll a, ll m = MOD) {
    return pw(a, m-2, m);
}

struct SegTree {
    vector<ll> tree;
    SegTree(vector<ll> array) {
        int p = 1;
        while (p < array.size()) p *= 2;
        tree = vector<ll>(p * 2);
        build(array);
    }
    void build(vector<ll> array) {
        int n = tree.size();
        for (int i = 0; i < array.size(); i++)
            tree[n/2 + i] = array[i];
        for (int i = n-1; i > 1; i--)
            tree[i/2] = add(tree[i/2], tree[i]);
    }
    ll query(int l, int r) { return _query(1,l,r,0,tree.size()/2-1); }
    ll _query(int ind, int l, int r, int bl, int br) {
        if (l > r) return 0;
        if (l == bl && r == br) return tree[ind];
        int m = (bl + br) / 2;
        return add(_query(ind*2, l, min(m,r), bl, m),
            _query(ind*2 + 1, max(m+1,l), r, m+1, br));
    }
    void update(int ind, int val) {
        ind = ind + tree.size() / 2;
        int diff = add(val, -tree[ind]);
        for (; ind > 0; ind /= 2) 
            tree[ind] = add(tree[ind], diff);
    }
    
    ll get(int ind) {
        return tree[ind + tree.size()/2];
    }
};

struct DSU {
    vector<int> parent, size;
    vector<vector<int>> nodes;
    DSU(int n) {
        parent.assign(n, -1); 
        size.assign(n, 1);
        nodes.assign(n, vector<int>());
        for (int i = 0; i < n; i++) {
            nodes[i].push_back(i);
        }
    }
    int find(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b) {
        int r1 = find(a); int r2 = find(b);
        if (r1 == r2) return;
        if (size[r2] > size[r1]) swap(r1, r2);
        size[r1] += size[r2];
        for (auto node: nodes[r2]) {
            nodes[r1].push_back(node);
            size[node] = size[r1];
        }
        nodes[r2].clear();
        parent[r2] = r1;
    }
};

int main() {
    fastio
    int n, q; cin >> n >> q;

    ll iBASE = inverse(BASE);
    ll cur = 1, icur = 1;
    vector<ll> array(2*n), pows(2*n), ipows(2*n);
    for (int i = 0; i < 2*n; i++) {
        if (i < n) array[i] = mult(i, cur);
        else array[i] = mult(2*n-1-i, cur);
        pows[i] = cur;
        ipows[i] = icur;
        cur = mult(cur, BASE);
        icur = mult(icur, iBASE);
    }

    SegTree tree = SegTree(array);
    auto hash = [&](int l, int r) {
        return mult(tree.query(l, r), ipows[l]);
    };

    auto copy = [&](int v1, int v2) {
        ll value = mult(tree.get(v2), ipows[v2]);
        tree.update(v1, mult(value, pows[v1]));
        tree.update(2*n-1-v1, mult(value, pows[2*n-1-v1]));
    };
    // a b c d e e d c b a
    auto find_index = [&](int a, int b) {
        int l = a, r = (b + a)/2 + 1;
        while (l < r) {
            int lend = (l + r) / 2;
            int rend = b - (lend - a);
            if (hash(a, lend) == hash(2*n-1-b, 2*n-1-rend)) {
                l = lend + 1;
            } else {
                r = lend;
            }
        }
        assert(l >= a);
        return l;
    };

    DSU dsu = DSU(n);
    while (q--) {
        int query; cin >> query;
        if (query == 1) {
            int l, r; cin >> l >> r; l--, r--;
            if (dsu.size[dsu.find(0)] == n) continue;
            while (l < r) {
                int diff = find_index(l, r) - l;
                l += diff, r -= diff;
                assert(diff >= 0);
                if (l >= r) break;
                int big = dsu.find(l);
                int small = dsu.find(r);
                assert(big >= 0 && big < n);
                assert(small >= 0 && small < n);
                if (big != small) {
                    assert(dsu.size[small] > 0);
                    assert(dsu.size[big] > 0);
                    if (dsu.size[small] > dsu.size[big]) {
                        swap(big, small);
                    }
                    assert(dsu.nodes[small].size() <= dsu.nodes[big].size());
                    for (int v: dsu.nodes[small]) copy(v, big);
                    dsu.merge(l, r);
                }
                l++, r--;
            }
        } else {
            int a, b; cin >> a >> b; a--, b--;
            int x, y; cin >> x >> y; x--, y--;
            if ((b - a) != (y - x)) {
                cout<<"Not equal"<<endl;
                continue;
            }
            if (hash(x, y) == hash(a, b)) {
                cout<<"Equal"<<endl;
                continue;
            } 
            cout<<"Unknown"<<endl;
        }
    }
}