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
    vi counts(n), left(n), right(n, n-1);
    stack<pii> stk;
    for (int i = 0; i < n; i++) {
        cin >> counts[i];
        while (!stk.empty() && stk.top().first > counts[i]) {
            auto [val, ind] = stk.top();
            // can go no further.
            right[ind] = i - 1;
            stk.pop();
        }
        if (stk.empty()) {
            left[i] = 0;
        } else {
            auto [val, ind] = stk.top();
            if (val == counts[i]) {
                left[i] = left[ind];
            } else {
                left[i] = ind + 1;
            }
        }
        stk.push({counts[i], i});
    }
    /* for (int i = 0; i < n; i++) {
        dbg(counts[i])
        dbg(left[i])
        dbg(right[i])
        cerr<<"_____\n";
    } */

    ll s=0, e=0, r=-1;
    for (int i = 0; i < n; i++) {
        ll val = (right[i] - left[i] + 1) * (ll) counts[i];
        if ((val > r) ||
            (val == r && (left[i] + 1) < s)) {
            s = left[i] + 1;
            e = right[i] + 1;
            r = val;
        }
    }
    cout<<s<<" "<<e<<" "<<r;
}