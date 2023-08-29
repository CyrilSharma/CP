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
    int n; cin >> n;
    vll counts(n);
    for (int i = 0; i < n; i++) {
        cin >> counts[i];
    }
    sort(counts.begin(), counts.end());
    int best = n - 1;
    ll lsum = 0, rsum = counts[n-1];
    for (int i = n - 2; i >= 0; i--) {
        lsum += counts[i];
        if (lsum >= rsum) {
            best = i;
            rsum += lsum;
            lsum = 0;
        }
    }
    cout<<(n - best)<<endl;
}
