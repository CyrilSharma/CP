#include <bits/stdc++.h>
using namespace std;
int main() {
    using ll = long long;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), sums(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            sums[i] = sum;
        }
        int prev = n-1; int ans = 0;
        map<ll,ll> freq;
        for (int i = n-1; i >= 0; i--) {
            if (freq.count(sums[i]) == 0) freq[sums[i]] = 1;
            else freq[sums[i]]++;
            if (a[i] == 0) {
                int max = -1;
                for (auto const& [key, val]: freq) {
                    if (val > max) max = val;
                }
                ans += max;
                prev = i;
                freq = map<ll,ll>();
            }
        }
        if (a[0] != 0) ans += freq[0];
        cout<<ans<<"\n";
    }
}
/**
 * Lots of goofies in here.
 * 1. You determined the right approach quickly, but you took too long to tune it.
 * 2. What you should've done is examined one test case closely, and then made a rule.
 * 3. You also forgot to account for the condition at the beginning of the array, tsk tsk.
 */