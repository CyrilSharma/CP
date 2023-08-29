#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;

ll MOD = 998244353;
vector<ll> fact,ifact,inv,pow2;
ll add(ll a, ll b, ll m = MOD) {
    a+=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll mult(ll a, ll b, ll m = MOD) {
    if(abs(a)>=m) a%=m;
    if(abs(b)>=m) b%=m;
    a*=b;
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

int main() {
    //fastio
    ll n, m;
    cin >> n >> m;
    ll ans = 0; ll inv = m; ll prod = 1;
    vector<ll> facts;
    for (ll i=2; i<=n; i++) {
        ll cur = 0;
        if (prod<=m) {
            bool isp = true;
            for (auto f: facts)
                if (i%f==0) { isp=false; break; }
            if (isp) facts.push_back(i);
            if (isp) prod *= i;
        }
        inv = mult(inv, m/prod);
        ans = add(ans, add(pw(m,i), -inv));
    }
    printf("%lld\n", ans);
}