#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define maxVal 1000000000

int main() {
    int n, m;
    cin >> n >> m;
    int minl, minr;
    minl = -1; minr = maxVal;
    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        minl = max(minl, l);
        minr = min(minr, r);
    }
    if (minl <= minr) cout << minr - minl + 1 << "\n";
    else cout << 0 << "\n";
}