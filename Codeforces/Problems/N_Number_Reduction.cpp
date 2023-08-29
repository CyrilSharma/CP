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
        string x; int k;
        cin >> x >> k;
        int n = (int) x.size();
        vvi pos(10);
        for (int i = 0; i < n; i++) {
            pos[x[i]-'0'].push_back(i);
        }
        for (int i = 0; i < 10; i++) {
            reverse(pos[i].begin(), pos[i].end());
        }
        string ans = "";
        int start = 0; int iters = n-k;
        for (int i = 0; i < iters; i++) {
            for (int j = (i==0); j < 10; j++) {
                while (!pos[j].empty() && pos[j].back() < start) pos[j].pop_back();
                if (!pos[j].empty() && pos[j].back() - start <= k) {
                    ans += j + '0';
                    k -= pos[j].back() - start;
                    start = pos[j].back() + 1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}