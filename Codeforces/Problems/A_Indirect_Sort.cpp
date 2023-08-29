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
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout<<((a[0]==1)?"Yes":"No")<<endl;
    }
}
/**
 * @brief For easy problems look for concise tricks.
 * In general, always examine the extremes. What happens when the rule regards the smallest
 * or largest number?
 */