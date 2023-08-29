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
        int n; cin >> n;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int count = 0;
        int ind = 0;
        while (nums.size() >= 3 && ind < nums.size()) {
            int prev = (ind != 0) ? ind-1 : nums.size()-1;
            int next = (ind == nums.size()-1) ? 0 : ind+1;
            if (nums[prev] != nums[next]) {
                nums.erase(nums.begin()+ind);
                count++;
            }
            else ind++;
        }
        for (auto num: nums) cerr<<num<<" ";
        cerr<<"\n";

        ind = 0;
        while (nums.size() > 0 && ind < nums.size()) {
            int prev = (ind != 0) ? ind-1 : nums.size()-1;
            int next = (ind == nums.size()-1) ? 0 : ind+1;
            if (nums[prev] == nums[next] && prev != next) {
                nums.erase(nums.begin()+ind);
                nums.erase(nums.begin()+next);
                count++;
            } else if (prev == next) {
                nums.erase(nums.begin()+ind);
                count++;
            }
            else ind++;
        }
        for (auto num: nums) cerr<<num<<" ";
        cerr<<"\n";
        cout<<count<<"\n";
    }
}