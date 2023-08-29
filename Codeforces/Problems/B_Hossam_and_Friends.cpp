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

int main() {
    fastio
    int t; cin >> t; //t=1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vvi g(n, vi());
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            if (y > x) swap(x, y);
            // end points point to all start points.
            g[x-1].push_back(y-1);
        }
        for (int i = 0; i < n; i++)
            sort(g[i].begin(), g[i].end());

        ll l=0, r=0, ans=0;
        while (l<n && r<n) {
            if (g[r].size()==0) ans+=(r-l+1), r++;
            else {
                if (l <= g[r].back()) l++;
                else ans+=(r-l+1), r++;
            }
        }
        cout<<ans<<endl;
    }
}
/**
 * @brief You knew the output would be large, yet forgot to use LL :/
 * Didn't consider the l++ condition carefully enough.
 * Should've thought of an easier way to validate (just store closest r endpoint).
 */