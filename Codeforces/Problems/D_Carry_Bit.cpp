#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using vi = vector<int>;
using ll = long long;

ll MOD = (ll)(1e9 + 7);
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
    ll n, k;
    cin >> n >> k;
    ll tot = 0;
    //cout<<fixed<<setprecision(0);
    if (k == 0) {
        printf("%lld\n", pw(3, n));
        return 0;
    } else if (n == k) {
        printf("%lld\n", pw(3, n-1));
        return 0;
    }
    init(n);
    for (ll q = 2; q <= min(2*k+1, n); q++) {
        ll b = q/2;
        if (q%2 == 0) {
            tot = add(tot, mult(pw(3, n-q+1), mult(nck(k-1, b-1), nck(n-k-1, b-1))));
            tot = add(tot, mult(pw(3, n-q), mult(nck(k-1, b-1), nck(n-k-1, b-1))));
        } else {
            tot = add(tot, mult(pw(3, n-q+1), mult(nck(k-1, b-1), nck(n-k-1, b))));
            tot = add(tot, mult(pw(3, n-q), mult(nck(k-1, b),nck(n-k-1, b-1))));
        }
    }
    printf("%lld\n", tot);
    //cout<<tot<<"\n";
}
/**
 * Every time you work with long longs, you must use
 * cout<<fixed<<setprecision(0)!!!!!!!
 * -- Only pw function can be used. NOT POW
 */