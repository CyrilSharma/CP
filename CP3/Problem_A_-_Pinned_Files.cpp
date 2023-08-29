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
    int p1, u1; cin >> p1 >> u1;
    int n = p1 + u1;
    vi start(n+1);
    for (int i = 0; i < n; i++) {
        cin >> start[i+1];
    }

    int p2, u2; cin >> p2 >> u2;
    vi end(n+1), indexes(n+1);
    for (int i = 0; i < n; i++) {
        cin >> end[i+1];
        indexes[end[i+1]] = i+1;
    }

    auto check = [&](int ignore) {
        int last = -1;
        for (int i = 1; i <= n; i++) {
            if (indexes[start[i]] <= ignore) {
                continue;
            }
            if (last == -1) {
                last = indexes[start[i]];
                continue;
            }
            if (last + 1 != (indexes[start[i]])) {
                return false;
            }
            last = indexes[start[i]];
        }
        return true;
    };

    auto unpin = [&](int index) {
        for (int i = index; i < n - u1; i++) {
            int temp = start[i];
            start[i] = start[i+1];
            start[i+1] = temp;
        }
    };

    auto unpinLarge = [&](int pins) {
        cerr<<"______"<<endl;
        dbg(pins)
        int best = -1;
        for (int i = 1; i <= pins; i++) {
            if (indexes[start[i]] > best) {
                best = i;
            }
        }
        dbg(best)
        unpin(best);
        cerr<<"______"<<endl;
    };
    dbg(check(0));
    dbg(check(1));
    dbg(check(2));
    int best = 1e9;
    for (int unpins = 0; unpins <= p1; unpins++) {
        for (int i = 0; i <= n; i++) {
            if (check(i)) {
                dbg(i)
                dbg(unpins)
                dbg(abs(p2 - i))
                int cur = i + unpins + abs(p2 - i);
                best = min(cur, best);
            }
        }
        if (p1 - unpins > 0) {
            unpinLarge(p1 - unpins);
            for (int i = 1; i <= n; i++) 
                cerr<<start[i]<<" ";
            cerr<<endl;
        }
    }
    cout<<best<<endl;
}