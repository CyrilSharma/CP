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
    int n; cin >> n;
    vi a(n);
    int m=-1;
    bool eq=true, eq50=true, has50=false, valid=true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i>0 && a[i] != a[i-1])
            eq=false;
        
        int mod = a[i]%10;
        if (mod==5 || mod==0) {
            has50=true;
            if (i>0 && !((a[i-1]+5)/10 == (a[i]+5)/10))
                eq50=false;
            continue;
        } else {
            eq50=false;
        }

        bool cond = (mod==3 || mod==6 || mod==7 || mod==9);
        int phase = (a[i]/10)%2;
        if (m==-1) {
            m = cond ? phase : !phase;
            continue;
        }
        if (phase == m) {
            if (!cond) valid=false;
        } else {
            if (cond) valid=false;
        }
    }
    if (eq) {
        cout<<"Yes"<<endl;
        return;
    } else if (eq50) {
        cout<<"Yes"<<endl;
        return;
    } else if (has50) {
        cout<<"No"<<endl;
        return;
    }
    cout<<((valid)?"Yes":"No")<<endl;
}

int main() {
    fastio
    int t; cin >> t;// t=1;
    while (t--) {
        solve();
    }
}