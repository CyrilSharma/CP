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
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        cout << nums[1] << "\n";
    }
}