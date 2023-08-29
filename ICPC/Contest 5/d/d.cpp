#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, w;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> w;
        int sum = 0;
        for (int j = 1; j < w; j++) {
            if (w%j==0) {
                sum += j;
            }
        }
        if (sum == w) {
            total++;
        }
    }
    cout << total;
}