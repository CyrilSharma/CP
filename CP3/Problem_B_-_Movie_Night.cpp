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

// compressing to SCCs might be easiest actually.
int main() {
    // need to account for tails connected to cycles.
    fastio
    int n; cin >> n;
    vi req(n);
    for (int i = 1; i <= n; i++) {
        int y; cin >> y;
        req[i] = y;
    }

    vi marked(n);
    vi cycle(n);
    vi branches(n);
    int ncycles = 0;
    for (int i = 0; i < n; i++) {
        if (marked[i] != 0) continue;
        stack<int> s;
        int cur = i;
        while (!marked[cur]) {
            marked[cur] = 1;
            s.push(cur);
            cur = req[cur];
        }
        // if the index i stopped at was a cycle...
        if (cycle[cur]) {
            branches[cycle[cur]]++;
            continue;
        }

        // if the index i stopped at wasn't a cycle...
        int start = cur;
        int node = -1;
        while (node != start) {
            node = s.top(); s.pop();
            cycle[node] = ncycles + 1;
        }
        ncycles++;
    }
    // 
}