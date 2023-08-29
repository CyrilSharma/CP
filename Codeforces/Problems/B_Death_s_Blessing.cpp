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
        int n; cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        ll asum = accumulate(a.begin(), a.end(), 0LL);
        ll bsum = accumulate(b.begin(), b.end(), 0LL);
        ll maxb = *max_element(b.begin(), b.end());
        cout<<asum+bsum-maxb<<endl;
    }
}