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
    int t; cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vi x(n); set<int> seen;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            seen.insert(x[i]);
        }

        // is the interval [l, r] done?
        auto check = [&](int l, int r) {
            for (int i=l; i<=r; i++) {
                if (seen.count(i) == 0) return false;
            }
            return true;
        };

        // find last unseen element.
        auto search = [&](int l, int r) {
            while (l < r) {
                //dbg(l); dbg(r);
                int m = (l + r) >> 1;
                if (check(m+1, r)) r=m;
                else l=m+1;
            }
            return l;
        };

        /* for (auto el: x) cerr<<el<<" "; cerr<<endl;
        dbg(search(-1, x[n-1])); */

        if (seen.size()==p) cout<<0<<endl;
        else if (search(-1, x[n-1]) != -1) {
            // increment number.
            int ans = p-x[n-1];
            seen.insert(0);
            bool overflow=true;
            for (int i=n-2; i>=0; i--) {
                if (x[i]+1!=p) {
                    seen.insert(x[i]+1);
                    overflow=false;
                    break;
                }
            }
            if (overflow) seen.insert(1);
            int dest = search(-1, x[n-1]);
            if (dest != -1) cout<<ans+dest<<endl;
            else cout<<ans<<endl;
        } else {
            int dest = search(x[n-1], p-1);
            cout<<dest-x[n-1]<<endl;
        }
    }
}
/**
 * @brief CLEAN.
 * Took a while, but I think I understand binary search much more now.
 */