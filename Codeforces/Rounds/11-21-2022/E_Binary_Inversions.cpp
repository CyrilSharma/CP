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
        ll n; cin >> n;
        ll sum = 0;
        vector<ll> nums(n);
        vector<ll> sums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
            sums[i] = sum;
        }
        ll diff = 0;
        ll total = 0;
        for (int i = 0; i < n; i++) {
            int psum = (i==0) ? 0 : sums[i-1];
            if (nums[i] == 1) {
                diff = max(diff, psum - (n-1-i - (sums[n-1] - sums[i])));
            }
            if (nums[i] == 0) {
                diff = max(diff, (n-1-i - (sums[n-1] - sums[i])) - psum);
                total += psum;
            }
        }
        cout << total+diff << "\n";
    }
}