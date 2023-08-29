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
        int l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        if (a==b) cout<<0<<endl;
        else if (abs(b-a)>=x) cout<<1<<endl;
        else if ((abs(r-b)>=x && abs(r-a)>=x) || (abs(l-b)>=x && abs(l-a)>=x)) cout<<2<<endl;
        else if ((abs(r-b)>=x || abs(l-b)>=x) && (abs(r-a)>=x || abs(l-a)>=x)) cout<<3<<endl;
        else cout<<-1<<endl;
    }
}