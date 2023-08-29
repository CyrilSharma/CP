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
    int n, x;
    cin >> n >> x;
    vi a(n);
    vi count(500001);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }
    for (int i = 1; i < x; i++) {
        if (count[i]%(i+1) != 0) {
            cout<<"No"<<endl;
            return;
        }
        int div = count[i]/(i+1);
        count[i+1]+=div;
    }
    cout<<"Yes"<<endl;
}

int main() {
    fastio
    solve();
}