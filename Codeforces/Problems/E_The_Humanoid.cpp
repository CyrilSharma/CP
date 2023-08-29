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
        ll n, h;
        cin >> n >> h;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll best=-1;
        for (int mask=0; mask<8; mask++) {
            int cmask=mask;
            int g=2; int b=1;
            ll ch = h; ll eaten=0;
            for (int i = 0; i < n; i++) {
                if (a[i] < ch) ch+=(ll)(a[i]/2), eaten++;
                else if (g>0 && cmask&1) cmask>>=1, g--, ch*=2, i--;
                else if (b && cmask%2==0) cmask>>=1, b--, ch*=3, i--;
                else break;
            }
            best=max(best, eaten);
        }
        cout<<best<<endl;
    }
}