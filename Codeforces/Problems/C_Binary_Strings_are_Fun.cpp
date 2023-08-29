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

ll MOD = 998244353;
ll add(ll a, ll b, ll m = MOD) {
    a+=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll pw(ll a, ll b, ll m = MOD) {
    assert(b >= 0);  // can return 0 if desired
    if(abs(a)>=m) a%=m;
    if(a==0 && b==0) return 0; // value of 0^0
    ll r=1;
    for(; b; b >>= 1) {
        if(b&1) r=mult(r,a,m);
        a=mult(a,a,m);
    }
    return r;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll ans=0; int count=0;
    for (int ind=0; ind<n; ind++) {
        char c = s[ind];
        if (ind>0 && c==s[ind-1]) count++;
        else count=1;
        ans=add(ans, pw(2,count-1));
    }
    cout<<ans<<endl;
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        solve();
    }
}