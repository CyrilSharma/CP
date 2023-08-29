#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        long long sum = 0;
        vector<long long> sums(n);
        map<long long,int> mode;
        for (int i = 0; i < n; i++) {
            sum += (long long) nums[i];
            sums[i] = sum;
            cout << sums[i] << " ";
            if (!mode.count(sums[i]))
                mode[sums[i]] = 1;
            else {
                mode[sums[i]]++;
            }
        }


        int max = 0;
        for (auto const& [key, val]: mode) {
            if (val > max) max = val;
        }
        cout << max << "\n";
    }
}