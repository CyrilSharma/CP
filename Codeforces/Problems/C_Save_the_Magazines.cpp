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
        vector<char> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<ll> nums(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += (s[i]=='1') ? nums[i] : 0;
        }
        ll small = 1e18;
        bool prev = false;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') {
                prev = true;
                small = min(small, nums[i]);
            }
            if (s[i] == '0') {
                if (prev) {
                    small = min(small, nums[i]);
                    sum += (nums[i] - small);
                }
                prev = false;
                small = 1e18;
            }
        }
        cout<<sum<<endl;
    }
}