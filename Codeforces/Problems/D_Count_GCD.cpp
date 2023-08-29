#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;

ll MOD = 998244353;

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

vector<ll> factorize(ll a) {
    vector<ll> factors;
    for (ll d=2; d*d <= a; d++) {
        bool isf = false;
        while (a%d==0) a/=d, isf=true;
        if (isf) factors.push_back(d);
    }
    if (a != 1) factors.push_back(a);
    return factors;
}

int main() {
    //fastio
    int t; cin >> t;
    while (t--) {
        ll n, m;
        cin>>n>>m;
        vector<ll> nums(n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (i>0 && nums[i-1]%nums[i] != 0) ok=false;
        }
        if (!ok) {
            cout<<"0\n";
            continue;
        }
        vector<ll> factors = factorize(nums[0]);
        ll ans = 1;
        for (int i = 1; i < n; i++) {
            ll r = nums[i-1] / nums[i];
            ll mprod = m / nums[i];
            vector<ll> rfacs;
            for (auto f: factors) 
                if (r%f==0) rfacs.push_back(f);
            ll sz = (ll)rfacs.size();
            ll cur = 0;
            for (ll mask=0; mask < 1<<sz; mask++) {
                ll prod=1; ll on=0;
                for (ll j=0; j < sz; j++) {
                    if (mask & (1<<j)) on++, prod*=rfacs[j];
                }
                if (on%2==0) cur = add(cur, mprod/prod);
                else cur = add(cur, -mprod/prod);
            }
            ans = mult(ans, cur);
        }
        printf("%lld\n", ans);
    }
}