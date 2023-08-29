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
    int n, m; cin >> n >> m;
    ll sum = 0;
    vi nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    sort(nums.rbegin(), nums.rend());
    auto test = [&](int x) {
        int l = x; int r = n-1;
        while (l < r) {
            if (nums[l] + nums[r] > m) return false;
            l++; r--;
        }
        return true;
    };
    int l = 0; int r = n-1;
    while (l < r) {
        int m = (l + r) / 2;
        if (test(m)) r=m;
        else l=m+1;
    }
    cout << sum + l + 1 << endl;
}