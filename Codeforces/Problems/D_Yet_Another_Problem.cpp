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
    int n, q; 
    cin >> n >> q;
    vll sums(n+1), xors(n+1), prevs(n+1,-1);
    map<int,int> odd, even;
    int acc = 0; ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        acc ^= a;
        xors[i] = acc;
        if (i%2==0 && odd.count(acc)>0) {
            prevs[i] = odd[acc];
        } else if (i%2==1 && even.count(acc)>0) {
            prevs[i] = even[acc];
        }
        if (i%2==0) even[acc] = i;
        else odd[acc] = i;
        sum += a; 
        sums[i] = sum;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (xors[l-1] != xors[r]) cout<<"-1\n";
        else if (sums[r]-sums[l-1]==0) cout<<"0\n";
        else if (prevs[r] != -1 && prevs[r] >= l-1) {
            if ((r-l+1)%2==0) {
                if (sums[r] - sums[prevs[r]] == 0 ||
                    sums[prevs[r]] - sums[l-1] == 0)
                    cout<<"1\n";
                else cout<<"2\n";
            }
            else cout<<"1\n";
        } else cout<<"-1\n";
    }
}
/**
 * @brief I'm too lazy to fix this.
 * This is casework hell, and I utterly failed it.
 * Next time I will write out the cases before
 * Wasting 2 hours doing something stupid.
 */