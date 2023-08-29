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
    vvi graph(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < m; i++) {
            char c; cin >> c;
            graph[i][j] = c-'0';
        }
    }
}
/**
 * @brief Come back when you understand graph matching algorithmns.
 */