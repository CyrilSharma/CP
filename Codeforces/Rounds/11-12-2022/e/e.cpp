#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        long long sum = 0;
        vector<long long> sums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
            sums[i] = sum;
        }
        // 
    }
}