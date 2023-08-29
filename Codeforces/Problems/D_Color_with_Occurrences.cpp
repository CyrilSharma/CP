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

void test() {
    string s; cin >> s;
    int n; cin >> n;
    vector<string> matches(n);
    for (auto &m: matches) cin >> m;
    
    int INF = 1e9;
    int l = (int)s.size();
    vi dp(l, INF), prev(l);
    for (int i = 0; i < l; i++) {
        bool covered = dp[i] != INF;
        for (auto &m: matches) {
            int sz = (int)m.size();
            if (i + sz >= l) continue;
            //dbg(s.substr(i, sz));
            //dbg(m);
            if (s.substr(i, sz) != m) continue;
            dbg(i);
            covered = true;
            if (dp[i] == INF) {
                if (i==0) dp[i] = 1;
                else dp[i] = dp[i-1] + 1;
            }
            for (int j = 1; j <= sz; j++) {
                if (dp[i] + 1 < dp[i+j]) {
                    dp[i+j] = dp[i] + 1;
                    prev[i+j] = i;
                }
            }
        }
        dbg(dp[i]);
        if (!covered) {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<dp[l-1]<<endl;
}

int main() {
    fastio
    int t; cin >> t; t=1;
    while (t--) {
        test();
    }
}