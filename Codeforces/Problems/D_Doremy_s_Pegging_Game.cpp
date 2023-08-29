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

ll MOD;
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

ll inverse(ll a, ll m = MOD) {
    return pw(a,m-2);
}

ll nck(ll a, ll b) {
    if(a<b) return 0;
    if(b==0) return 1;
    if(a==b) return 1;
    return mult(fact[a], mult(ifact[b],ifact[a-b]));
}

void init(ll _n) {
    fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
    fact.resize(_n+1); ifact.resize(_n+1); inv.resize(_n+1); pow2.resize(_n+1);
    pow2[0] = 1; ifact[0] = 1; fact[0] = 1;
    for (int i = 1; i <= _n; i++){
        pow2[i] = add(pow2[i-1], pow2[i-1]);
        fact[i] = mult(fact[i-1], i);
    }
    ifact[_n] = inverse(fact[_n]);
    for (int i = _n-1; i >= 1; i--){
        ifact[i] = mult(ifact[i+1], i+1);
    }
    for (int i = 1; i <= _n; i++) {
        inv[i] = mult(fact[i-1], ifact[i]);
    }
}

int main() {
    fastio
    ll n, p;
    cin >> n >> p;
    MOD = p;

    init(n+1);
    ll t = n/2;
    auto f = [&](ll k) {
        if (k < t) return 0LL;
        if (k >= n-1) return fact[n];
        return mult(n, mult(fact[k], nck(n-t-1,k-t)));
    };
    ll ans = 0;
    for (ll k = 0; k < n; k++) {
        ans = add(ans, add(f(k+1), -mult((n-k),f(k))));
    }
    cout<<ans<<endl;
}