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

int gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi nums(n);
        int div; int large = -1;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            large = max(large, nums[i]);
            if (i==0) div = nums[i];
            else div = gcd(nums[i], div);
        }
        cout<<large/div<<endl;
    }
}