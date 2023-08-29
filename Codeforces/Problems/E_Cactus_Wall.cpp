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
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        auto out = [&n, &m](int x, int y) {
            return (x < 0 || x >= m || y < 0 || y >= n);
        };

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        auto valid = [&](int x, int y) {
            if (out(x,y)) return false;
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (!out(nx, ny) && board[ny][nx]=='#')
                    return false;
            }
            return true;
        };

        vvi dist(n, vi(m, 1e9));
        deque<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0]=='#') {
                q.push_front({0,i});
                dist[i][0] = 0;
            } else if (valid(0,i)) {
                q.push_back({0,i});
                dist[i][0] = 1;
            }
        }

        int dgx[] = {1, 1, -1, -1};
        int dgy[] = {1, -1, -1, 1};
        vector<vector<pair<int,int>>> prev(n, vector<pair<int,int>>(m));
        while (q.size() != 0) {
            auto [x, y] = q.front(); q.pop_front();
            int d = dist[y][x];
            for (int ind=0; ind<4; ind++) {
                int nx = x+dgx[ind];
                int ny = y+dgy[ind];
                if (valid(nx, ny)) {
                    int w = (board[ny][nx] != '#');
                    if (d+w < dist[ny][nx]) {
                        prev[ny][nx] = {x, y};
                        dist[ny][nx] = d+w;
                        if (w) q.push_back({nx, ny});
                        else q.push_front({nx, ny});
                    }
                }
            }
        }

        int best=1e9, bestInd=-1;
        for (int i=0; i<n; i++) {
            if (dist[i][m-1] < best) {
                best = dist[i][m-1];
                bestInd = i;
            }
        }

        /* dbg(best); dbg(bestInd);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j]==1e9) cerr<<"_"<<" ";
                else cerr<<dist[i][j]<<" ";
            }
            cerr<<endl;
        } */

        if (best==1e9) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            pair<int,int> cur = {m-1, bestInd};
            while (true) {
                auto [x, y] = cur;
                board[y][x] = '#';
                cur = prev[y][x];
                if (x==0) break;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout<<board[i][j];
                }
                cout<<endl;
            }
        }
    }
}
/**
 * @brief Learn 0-1 BFS / never, ever, ever again will you try some special approach from the editorial
 * without fully rationalizing it. You just presumed bfs would work because you saw it in the editorial,
 * despite instinctively knowing djikstras would've worked first try.
 */