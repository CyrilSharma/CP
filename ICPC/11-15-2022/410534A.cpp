#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> quant(n);
        for (int i = 0; i < n; i++) cin >> quant[i];
        sort(quant.begin(), quant.end());

        int sum = 0;
        vector<int> sums(n);
        for (int i = n-1; i >= 0; i--) {
            sum += quant[i];
            sums[n-i-1] = sum;
        }

        // see if you were clowning or not
        function<int(int,int,int)> search;
        search = [&](int val, int l, int r) {
            if (r - l <= 1) return r;
            int m = (l + r) / 2;
            if (val > sums[m]) l = m;
            else r = m;
            return search(val, l, r);
        };

        // needs to be a little more efficient.
        for (int i = 0; i < q; i++) {
            int x; cin >> x;
            auto ans = search(x,-1,n);
            if (ans == n) cout << "-1\n";
            else cout << ans+1 << "\n";
        }
    }
}