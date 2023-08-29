#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n; 
    cin >> m >> n;
    vector<vector<char>> map(m,vector<char>(n));
    pair<int,int> s, e;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            map[i][j] = c;
            if (c == 'S') {
                s = {i, j};
            } else if (c == 'E') {
                e = {i, j};
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    function<pair<int,int>(char,int,int)> bfs;
    bfs = [&](char c, int t, int cost) {
        vector<vector<int>> visited(m, vector<int>(n));
        vector<vector<int>> times(m, vector<int>(n));
        vector<vector<int>> costs(m, vector<int>(n));
        queue<pair<int,int>> q;
        q.push(s); visited[s.first][s.second] = 1; 
        while (q.size() != 0) {
            auto [y, x] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;    
                if (visited[ny][nx]) continue;
                if (ny == e.first && nx == e.second) 
                    return make_pair(times[y][x], costs[y][x]);
                if (map[ny][nx] != c) continue;
                times[ny][nx] = times[y][x] + t;
                costs[ny][nx] = costs[y][x] + cost;
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
        return make_pair((int)2e9, (int)2e9);
    };
    char letters[3] = {'B', 'C', 'W'};
    int times[3] = {3, 10, 10};
    int costs[3] = {2, 10, 5};
    char bestMode = 'r';
    int bestT = 2e9;
    int bestC = 2e9;
    for (int i = 0; i < 3; i++) {
        auto [t, c] = bfs(letters[i], times[i], costs[i]);
        if (t < bestT) {
            bestT = t;
            bestMode = letters[i];
        } else if (t == bestT) {
            if (c < bestC) {
                bestC = c;
                bestMode = letters[i];
            }
        }
    }
    if (bestMode == 'r') {
        cout << "None";
    } else {
        cout << bestMode;
    }
}