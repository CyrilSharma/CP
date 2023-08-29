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
        int m, s;
        cin >> m >> s;
        vi nums(m); 
        int large = -1; int sum = 0;
        for (int i = 0; i < m; i++) {
            cin >> nums[i];
            sum += nums[i];
            large = max(large, nums[i]);
        }
        int start = (large * (large + 1)) / 2 - sum;
        for (int i=large+1; i<=1000; i++) {
            if (start == s) {
                cout<<"YES\n";
                break;
            }
            if (start > s) {
                cout<<"NO\n";
                break;
            }
            start+=i;
        }
    }
}