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
    //fastio
    int t; cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vll a(n);
        for (auto &ai: a) cin >> ai;
        sort(a.begin(), a.end());
        int cx=x, status=1;
        while (cx < y) {
            int ub = *upper_bound(a.begin(), a.end());
            if (ub == a.end()) {
                status = 2; break;
            }
            cx += ub;
            if (cx < y) {
                cx -= (n - ub);
                if (cx <= x) {
                    status = -1;
                    break;
                }
            }
        }

        if (last==-1) printf("%lld\n", y-x);
        else if (x==y) printf("%d\n", last);
        else printf("%d\n", -1);
    }
}