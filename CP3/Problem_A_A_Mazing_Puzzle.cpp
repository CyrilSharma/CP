#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
int main() {
    int c, r, e;
    cin >> c >> r >> e;

    int c1, r1; char d1;
    cin >> c1 >> r1 >> d1;

    int c2, r2; char d2;
    cin >> c2 >> r2 >> d2;

    auto getDir = [](char c) {
        switch (c) {
            case 'E': return 0;
            case 'N': return 1;
            case 'W': return 2;
            case 'S': return 3;
        }
        return -1;
    };
    // S->3, E->0 => diff=3
    int rel = getDir(d2) - getDir(d1);
    vvi maze(r+1, vi(c+1, 0));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cwall, rwall;
        cin >> cwall >> rwall;
        // down
        maze[rwall][cwall] += 0b1000;
        // up
        maze[rwall + 1][cwall] += 0b0010;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int cwall, rwall;
        cin >> cwall >> rwall;
        // right
        maze[rwall][cwall] += 0b0001;
        // left
        maze[rwall][cwall + 1] += 0b0100;
    }

    auto illegal = [&](int y, int x) {
        if (y == 0 && x == e) return false;
        return (x<1 || x>c || y<1 || y>r);
    };

    auto done = [&](int y, int x) {
        return(x == e && y == 0);
    };

    auto compress = [](int x1, int y1, int x2, int y2) {
        return (x1 + (y1 << 6) + (x2 << 12) + (y2 << 18));
    };

    auto decompress = [](int hash) -> tuple<int,int,int,int> {
        int x1 = (hash & 0b111111);
        int y1 = ((hash >> 6) & 0b111111);
        int x2 = ((hash >> 12) & 0b111111);
        int y2 = ((hash >> 18) & 0b111111);
        return {x1, y1, x2, y2};
    };

    // R, U, L, D
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    // dbg(rel)
    int MAX = 2e7;
    auto brute_force = [&]() {
        bool found = false;
        pair<int,int> best = {MAX, MAX};
        vector<int> total_dist(MAX, MAX), bumps(MAX);
        int start = compress(c1, r1, c2, r2);
        total_dist[start] = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            auto [x1, y1, x2, y2] = decompress(node);
            for (int i = 0; i < 4; i++) {
                int bump1 = 0, bump2 = 0;
                int nx1=x1, ny1=y1, nx2=x2, ny2=y2;
                if (!done(y1, x1)) {
                    if (!(maze[y1][x1] & (1 << i)) &&
                        !(illegal(ny1 + dy[i], nx1 + dx[i]))) {
                        nx1 += dx[i];
                        ny1 += dy[i];
                    } else bump1 = 1;
                }
                if (!done(y2, x2)) {
                    int j = (i + rel + 4) % 4;
                    if (!(maze[y2][x2] & (1 << i)) &&
                        !(illegal(ny2 + dy[j], nx2 + dx[j]))) {
                        nx2 += dx[j];
                        ny2 += dy[j];
                    } else bump2 = 1;
                }

                int nbr = compress(nx1, ny1, nx2, ny2);
                int dist = total_dist[node] + 1;
                int nbumps = bumps[node] + bump1 + bump2;

                /* check for invalid transition */
                if (dist > total_dist[nbr]) continue;
                if (dist == total_dist[nbr] && nbumps >= bumps[nbr]) continue;
                if (bump1 & bump2) continue;
                
                total_dist[nbr] = dist;
                bumps[nbr] = nbumps;
                /* check for solution */
                if (done(ny1, nx1) && done(ny2, nx2)) {
                    found = true;
                    bool flag = false;
                    if (total_dist[nbr] == best.first) {
                        flag = bumps[nbr] < best.second;
                    } else {
                        flag = total_dist[nbr] < best.first;
                    }
                    if (flag) {
                        best.second = bumps[nbr];
                        best.first = total_dist[nbr];
                    }
                    continue;
                }
                if (nx1 == nx2 && ny1 == ny2) continue;
                if (found) continue;
                /* queue next state */
                q.push(nbr);
            }
        }
        assert(found);
        return best;
    };
    auto [forward, bumps] = brute_force();
    cout<<forward<<" "<<bumps<<endl;
}