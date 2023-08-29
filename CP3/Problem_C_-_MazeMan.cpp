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

int n, m;
char maze[100][100];
int marked[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ngroups = 0;
int ngroups_useful = 0;
int total_found = 0;
void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || 
            ny < 0 || ny >= n)
            continue;
        //cerr<<ny<<" "<<nx<<endl;
        if (marked[ny][nx]) 
            continue;
        if (maze[ny][nx] != '.' && 
            maze[ny][nx] != ' ')
            continue;
        marked[ny][nx] = ngroups + 1;
        if (maze[ny][nx] == '.')
            total_found++;
        dfs(ny, nx);
    }
}

int main() {
    fastio 
    cin >> n >> m;
    string s; getline(cin, s);
    vector<pii> starts;
    int total_exist = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < m; j++) {
            maze[i][j] = s[j];
            if (s[j] >= 'A' && s[j] <= 'W') {
                starts.push_back({i, j});
            } else if (s[j] == '.') {
                total_exist++;
            }
        }
    }
    for (auto start: starts) {
        auto [y, x] = start;
        if (!marked[y][x]) {
            int cur_found = total_found;
            dfs(y, x);
            ngroups++;
            if ((total_found - cur_found) != 0) {
                ngroups_useful++;
            }
        }
    }
    cout<<ngroups_useful<<" "<<(total_exist-total_found)<<endl;
}