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

void solve() {
    int n, x;
    cin >> n >> x;
    if (x >= (n/2 + 1) && x <= n-1) {
        cout<<-1<<endl;
        return;
    } else if (n%x != 0) {
        cout<<-1<<endl;
        return;
    }

    vi ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = i+1;
    }
    
    ll cur = x;
    vll factors = factorize(n);
    for (auto f: factors) {
        while (n % (cur*f) == 0) {
            ans[cur-1] = cur*f;
            cur *= f;
        }
    }
    ans[0]=x, ans[n-1]=1;
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        solve();
    }
}