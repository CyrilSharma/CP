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
    int n, k, a, b, a0, b0;
    cin >> n >> k >> a0 >> b0;
    vector<pii> ab(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        ab[i]={a,b};
    }
    if (a0 >= k) {
        cout << "YES\n"; return;
    } else if (a0 + b0 < k) {
        cout << "NO\n"; return;
    }
    sort(ab.begin(), ab.end(), [](pii l, pii r) {
        return l.first + l.second > r.first + r.second;
    });
    int goal = k - b0;
    for (int i = 0; i < n-1; i++) {
        if (ab[i].first + ab[i].second < goal) break;
        if (i+1 < n-1 && ab[i+1].first + ab[i+1].second >= goal) {
            cout << "YES\n"; return;
        } else if (ab[i].first >= goal) {
            cout << "YES\n"; return;
        }
        goal -= ab[i].second;
    }
    cout << "NO\n";
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/**
 * @brief In summary, give up way earlier.
 * We need to enforce a strict 30 min rule.
 * It's ridiculous to spend 2 hours on a problem whose editorial you read anyways.
 * Also, you didn't read the input correctly for the entire duration of that period.
 * Just because you've seen the problem before doesn't mean you shouldn't REREAD it.
 */