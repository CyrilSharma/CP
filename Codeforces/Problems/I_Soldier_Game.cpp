#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct item {
    ll solo;
    ll team;
    ll mn_solo;
    ll mn_team;
    ll mx_solo;
    ll mx_team;
};

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> a(n);
        item best = {(ll)1e18, (ll)1e18, (ll)1e18, (ll)1e18, 0, 0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            item cur = best;
            best.mn_solo = min(a[i], min(cur.mn_solo, cur.mn_team));
            best.mx_solo = max(a[i], max(cur.mx_solo, cur.mx_team));
            best.solo = min(
                cur.mn_solo, 
                best.mx_solo - best.mn_solo
            );

            best.mn_team = min(a[i], cur.mn_solo);
            best.mx_team = max(a[i], cur.mx_solo);
            best.team = min(
                cur.mn_team, 
                min(cur.mn_solo, a[i] + a[i-1])
            );
        }
        ll ans = min(best.solo, best.team);
        cout<<ans<<endl;
    }
}