#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

ll add(ll a, ll b, ll m) {
    a+=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll mult(ll a, ll b, ll m) {
    if(abs(a)>=m) a%=m;
    if(abs(b)>=m) b%=m;
    a*=b;
    if(abs(a)>=m) a%=m;
    if(a<0) a+=m;
    return a;
}

ll pw(ll a, ll b, ll m) {
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

ll inverse(ll a, ll m) {
    return pw(a, m-2, m);
}

int main() {
    fastio
    int n; cin >> n;
    cout<<
    auto hash = [](string s, ll b, ll m) {
        ll val=0, cur=1;
        for (int i = s.size() - 1; i >= 0; i--) {
            dbg(s[i])
            dbg(1LL*(s[i] - 'a'))
            val = add(val, 1LL * (s[i] - 'a') * cur, m);
            cur = mult(cur, b, m);
        }
        return val;
    };

    set<ll> hashes1, hashes2;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        dict[i] = s;
        hashes1.insert(hash(s, 29, 1e9+7));
        hashes2.insert(hash(s, 31, 1e9+9));
    }

    bool hastypos = false;
    for (int i = 0; i < n; i++) {
        ll shash1 = hash(dict[i], 29, 1e9+7);
        ll shash2 = hash(dict[i], 31, 1e9+9);
        ll cur1 = 1, cur2 = 1;
        ll rhash1 = 0, rhash2 = 0;
        for (int j = dict[i].size() - 1; j >= 0; j--) {
            rhash1 = add(rhash1, 1LL * (dict[i][j] - 'a') * cur1, 1e9+7);
            ll chash1 = add(shash1, -rhash1, 1e9+7);
            chash1 = mult(chash1, inverse(29, 1e9+7), 1e9+7);
            chash1 = add(chash1, rhash1, 1e9+7);
            chash1 = add(chash1, -1LL * (dict[i][j] - 'a') * cur1, 1e9+7);

            rhash2 = add(rhash2, 1LL * (dict[i][j] - 'a') * cur2, 1e9+9);
            ll chash2 = add(shash2, -rhash2, 1e9+9);
            chash2 = mult(chash2, inverse(31, 1e9+9), 1e9+9);
            chash2 = add(chash2, rhash2, 1e9+9);
            chash2 = add(chash2, -1LL * (dict[i][j] - 'a') * cur2, 1e9+9);
            if (hashes1.count(chash1) && hashes2.count(chash2)) {
                hastypos = true;
                cout<<dict[i]<<endl;
                break;
            }
            cur1 = mult(cur1, 29, 1e9+7);
            cur2 = mult(cur2, 31, 1e9+9);
        }
    }

    if (!hastypos) {
        cout<<"NO TYPOS"<<endl;
    }
}