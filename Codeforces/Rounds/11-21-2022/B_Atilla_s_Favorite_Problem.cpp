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
        int best = 0;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            best = max(c- 'a', best);
        }
        cout<<best+1<<"\n";
    }
}