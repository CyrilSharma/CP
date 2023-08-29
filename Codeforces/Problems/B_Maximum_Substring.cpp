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
        int nzero=0; int none=0;
        int lzero=0; int lone=0;
        int blzero=0; int blone=0;
        char prev='W';
        for (int i = 0; i < n; i++) {
            cin>>s[i];
            if (s[i]=='0') lzero++, nzero++;
            if (s[i]=='0' && prev!='0') blone=max(blone,lone), lone=0;
            if (s[i]=='1') lone++, none++;
            if (s[i]=='1' && prev!='1') blzero=max(blzero,lzero), lzero=0;
            prev=s[i];
        }
        blone=max(blone,lone);
        blzero=max(blzero,lzero);
        cout<<max({1LL*blone*blone, 1LL*blzero*blzero, 1LL*nzero*none})<<endl;
    }
}
/**
 * @brief Check boundary conditions!
 * Also always check for possible LL issues.
 */