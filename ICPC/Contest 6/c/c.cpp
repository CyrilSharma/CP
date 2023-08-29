#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, k; 
    cin >> t >> k;
    int b;
    vector<int> sourness;
    while (cin >> b) {
        sourness.push_back(b);
    }
    sort(sourness.begin(), sourness.end());
    int total = 0;
    int chosen = 0;
    for (int i = 0; i < sourness.size(); i++) {
        if (sourness[i] < t) continue;
        else {
            total += sourness[i];
            chosen++;
            if (chosen >= k) break;
        }
    }
    cout << total;
}