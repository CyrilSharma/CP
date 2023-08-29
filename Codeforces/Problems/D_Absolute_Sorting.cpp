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
        vi a(n);
        int t1=1e9, t2=-1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i==0) continue;
            if (a[i]>a[i-1]) t1=min(t1,(a[i]+a[i-1])/2);
            else if (a[i]<a[i-1]) t2=max(t2, (a[i]+a[i-1]+1)/2);
        }
        cout<<((t2<=t1) ? t1 : -1)<<endl;
    }
}