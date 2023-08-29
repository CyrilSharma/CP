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
    int n, m;
    cin >> n >> m;
    vi p(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        p[i] = a-1;
    }
    vvi parents(n, vi());
    vi deg(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        parents[b-1].push_back(a-1);
        deg[a-1]++;
    }

    for (int i = 0; i < n; i++) {
        priority_queue<pair<int,int>> q;
        for (int j = 0; j < n; j++) {
            if (deg[j] == 0 && i!=j) {
                q.push({p[j], j});
            }
        }

        vi tdeg(deg);
        bool done=false;
        int j=n-1, el;
        for (; j >= 0 && !done; j--) {
            if (q.empty()) done=true;
            else el=q.top().second, q.pop();
            if (done) continue;
            if (p[el] < j) done=true;
            for (auto parent: parents[el]) {
                tdeg[parent]--;
                if (tdeg[parent] == 0 && parent != i)
                    q.push({p[parent], parent});
            }
        }
        cout<<j+2<<" ";
    }
}

/**
 * @brief It looks clean but that made it really buggy.
 * Never write code like this again.
 * Don't leave side effects in your code for the sake of "looking clean".
 */