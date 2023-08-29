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
        int count = 0; bool valid = true;
        for (int i = n-1; i >= 0; i--) {
            if (s[i]=='A') count++;
            else count--;
            if (count < 0) {
                valid=false; break;
            }
        }
        if (valid) cout<<"Yes\n";
        else cout<<"No\n";
    }
}