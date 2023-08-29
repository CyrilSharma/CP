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

ll MOD = 1e9+7;
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

// new comparison functino.
auto best = [](pii a, pii b) -> pii {
    if (a.first != b.first) return (a.first > b.first) ? a : b;
    else return (a.second < b.second) ? a : b;
};

struct SparseTable {
    vector<int> lg;
    vector<vector<pii>> st;
    SparseTable(vector<pii> a) {
        int n = (int) a.size();
        lg = vector<int>(n+1);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i/2] + 1;
        int k = lg[n];

        st = vector<vector<pii>>(k+1, vector<pii>(n+1));
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = best(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    pii query(int l, int r) {
        int i = lg[r - l + 1];
        pii res = best(st[i][l], st[i][r - (1 << i) + 1]);
        return res;
    }
};

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pii> array(n);
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            array[i] = {tmp, i};
        }

        vvll sum(n, vll(m+1));
        vvll dp(n, vll(m+1));

        SparseTable sp(array);
        function<int(int,int)> count;
        count = [&](int l, int r) -> int {
            if (l > r) return -1;
            auto [vmax, pmax] = sp.query(l, r);
            int lmax = count(l, pmax-1); 
            int rmax = count(pmax+1, r);
            for (int i = 1; i <= m; i++) {
                if (lmax == -1 && rmax == -1) dp[pmax][i] = 1;
                else if (lmax == -1) dp[pmax][i] = sum[rmax][i];
                else if (rmax == -1) dp[pmax][i] = sum[lmax][i-1];
                else dp[pmax][i] = mult(sum[lmax][i-1], sum[rmax][i]);
                sum[pmax][i] = add(sum[pmax][i-1], dp[pmax][i]);
            }
            return pmax;
        };
        count(0, n-1);
        cout << sum[sp.query(0,n-1).second][m] << endl;
    }
}