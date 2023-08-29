#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            nums[i] = c - '0';
        }
        long long total = 0;
        int l = 0; int r = 0;
        vector<int> counts(10);
        while (r < n) {
            while (counts[nums[r]] == 0 && r < n) {
                counts[nums[r]]++;
                r++;
            } 
            int size = r - l;
            total += size * (size + 1) / 2;
            counts[nums[l]]--;
            l++;
        }
        cout << total << "\n";
    }
}