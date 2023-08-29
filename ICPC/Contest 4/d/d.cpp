#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> hol(m)
    for (int i = 0; i < m; i++) {
        cin >> hol[i];
    }
    hol.push_back(n);

    vector<int> costs(m+1);
    for (int i=1; i <= m; i++) {
        int cost = (hol[i] - hol[i-1]) / (y/2);
        if (hol[i] - hol[i-1] - 1 <= x)
        costs[i] = costs[i-1] + cost;
    }
    cout << costs[m];
}