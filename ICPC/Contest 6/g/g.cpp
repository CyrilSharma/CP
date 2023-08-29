#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> layer(6);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) {
            layer[1]++;
        }
        else if (layer[a-1] > 0) {
            layer[a-1]--;
            layer[a]++;
        }
    }
    cout << layer[5];
}