#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        ll n, c, d;
        cin >> n >> c >> d;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end(), greater<ll>());

        ll sum = 0;
        vector<ll> sums(d);
        for (int i = 0; i < d; i++) {
            sum += (i<n) ? nums[i] : 0;
            sums[i] = sum;
        }

        if (sums[min(d-1,n-1)] >= c) {
            cout << "Infinity\n";
            continue;
        }
        int status = -1;
        for (ll k = d-1; k >= 0; k--) {
            ll rpt = k + 1;
            ll full = d / rpt;
            ll rem = d % rpt;
            ll remsum = rem==0 ? 0 : sums[rem-1];
            ll val = full * sums[k] + remsum;
            if (val >= c) {
                cout << k << "\n";
                status = 0;
                break;
            }
        }
        if (status == -1) 
            cout << "Impossible\n";
    }
}