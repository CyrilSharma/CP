#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, M, c, m;
    cin >> n >> M;

    struct elephant {
        string name;
        int c;
        int m;
    };

    string s;
    int bestC = -1;
    elephant bestEl;
    for (int i = 0; i < n; i++) {
        cin >> s >> c >> m;
        elephant e = {s,c,m};
        if ((c * (int)s.size() > bestC) && (m <= M)) {
            bestC = c * s.size();
            bestEl = e;
        }
    }
    if (bestC == -1) cout << "dead meme :(\n";
    else cout << bestEl.name << " to the moon!\n";
}