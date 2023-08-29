#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pii> nums(n); 
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            nums[i] = {a, i};
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            auto [num, ind] = nums[i];
            cout << min(ind+2,n) << " ";
        }
        cout << endl;
    }
}