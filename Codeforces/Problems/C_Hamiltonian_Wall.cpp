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

void solve() {
    int m; cin >> m;
    vector<string> wall(2);
    for (auto& s: wall) cin >> s;

    int first = -1;
    for (int i = 0; i < m; i++) {
        if (wall[0][i] != wall[1][i]) {
            first = i; break;
        }
    }
    if (first==-1) {
        cout<<"YES"<<endl;
        return;
    }

    int row;
    row = wall[0][first]!='B';
    for (int i = first; i < m; i++) {
        if (wall[row][i]=='W') {
            cout<<"NO"<<endl;
            return;
        }
        if (wall[!row][i]=='B') {
            row ^= 1;
        }
    }

    row = wall[0][first]!='B';
    for (int i = first; i >= 0; i--) {
        if (wall[row][i]=='W') {
            cout<<"NO"<<endl;
            return;
        }
        if (wall[!row][i]=='B') {
            row ^= 1;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        solve();
    }
}