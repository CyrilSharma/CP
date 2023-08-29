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
    ll n, m;
    cin >> n >> m;

    ll temp = n;
    int n2=0, n5=0;
    while (temp%2==0) n2++, temp/=2;
    while (temp%5==0) n5++, temp/=5;
    n2-=min(n2,n5), n5-=min(n2,n5);

    ll cur = 1;
    while (true) {
        if (n5>0 && cur*2 <= m) cur*=2, n5--;
        else if (n2>0 && cur*5 <= m) cur*=5, n2--;
        else if (cur*10 <= m) cur*=10;
        else break;
    }
    if (m/cur > 1) cur = (m/cur) * cur;
    cout<<n*cur<<endl;
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        solve();
    }
}