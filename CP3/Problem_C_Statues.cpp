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
    int n, m; cin >> n >> m;
    vi statues;
    vvi grid(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != -1) {
                statues.push_back(grid[i][j]);
            }
        }
    }

    sort(statues.begin(), statues.end());
    int best = 1e9;
    for (int mode = 0; mode < 4; mode++) {
        int cur = 0, total = 0;
        for (int dg = 0; dg < n + m; dg++) {
            set<int> d;
            int length = 0;
            /* why did i not just make an array :/ */
            int startJ = (mode%2) ? m - 1 - dg : dg;
            int startI = (mode/2) ? n - 1 : 0; 
            int incJ = (mode%2) ? 1 : -1;
            int incI = (mode/2) ? -1 : 1;
            for (int i=startI, j=startJ, 
                count=0; count <= dg; count++,
                i+=incI, j+=incJ) {
                if (i < 0 || i >= n ||
                    j < 0 || j >= m) {
                    continue;
                }
                if (grid[i][j] == -1) {
                    continue;
                }
                d.insert(grid[i][j]);
                length++;
            }
            for (int i = cur; i < cur + length; i++) {
                if (i >= statues.size()) break;
                if (!d.count(statues[i])) {
                    total++;
                }
            }
            cur += length;
        }
        best = min(best, total);
    }
    cout<<best<<endl;
}