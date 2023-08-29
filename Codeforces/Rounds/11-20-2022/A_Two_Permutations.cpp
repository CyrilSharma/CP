#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n - (a + b) >= 2) cout<<"Yes"<<"\n";
        else if (a == n && b == n) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
}