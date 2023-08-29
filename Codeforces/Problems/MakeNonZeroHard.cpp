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
        if ((sum % 2 + 2) % 2 == 1) {
            cout << "-1\n";
            continue;
        }

        int prevInd1 = 0; int prevInd2 = 0;
        int prev; int cur;
        int nonzero = 0;
        vector<pair<int,int>> partitions;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nonzero++;
                if (nonzero == 1) {
                    prev = nums[i];
                    prevInd2 = i;
                } else if (nonzero == 2) {
                    cur = nums[i];
                }
            }
            if (nonzero == 2) {
                if (prev == -1 * cur) {
                    if (prevInd2 > prevInd1)
                        partitions.push_back({prevInd1, prevInd2-1});
                    partitions.push_back({prevInd2, prevInd2});
                    if (prevInd2 < i-1)
                        partitions.push_back({prevInd2+1, i-1});
                    partitions.push_back({i, i});
                } else {
                    if (prevInd2 > prevInd1)
                        partitions.push_back({prevInd1, prevInd2-1});
                    if (prevInd2 < i-1)
                        partitions.push_back({prevInd2, prevInd2});
                    if (prevInd2+1 < i-1)
                        partitions.push_back({prevInd2+1, i-2});
                    partitions.push_back({i-1, i});
                }
                nonzero = 0;
                prevInd1 = i + 1;
            } else if (i == n-1) {
                partitions.push_back({prevInd1, i});
            }
        }
        cout << (int)partitions.size() << "\n";
        for (auto part: partitions) {
            auto [l, r] = part;
            cout << l+1 << " " << r+1 << "\n";
        }
    }
}