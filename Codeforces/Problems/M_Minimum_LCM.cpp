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
        int best=1;
        for (int i = 2; i*i <= n; i++) {
            if (n%i==0) {
                best=n/i;
                break;
            }
        }
        cout<<n-best<<" "<<best<<endl;
    }
}