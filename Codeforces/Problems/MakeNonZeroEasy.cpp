#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }
        if (n % 2 == 1) {
            cout << "-1\n";
            continue;
        }
        vector<pair<int,int>> partitions;
        for (int i = 0; i < n-1; i+=2) {
            if (nums[i] == nums[i+1]) {
                partitions.push_back({i,i+1});
            } else {
                partitions.push_back({i,i});
                partitions.push_back({i+1,i+1});
            }
        }
        cout << (int)partitions.size() << "\n";
        for (auto part: partitions) {
            auto [l, r] = part;
            cout << l+1 << " " << r+1 << "\n";
        }
    }
}