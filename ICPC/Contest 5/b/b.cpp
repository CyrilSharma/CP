#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> hairs(1001);
    vector<int> before(n);
    vector<int> after(n);
    for (int i = 0; i < n; i++) {
        cin >> before[i];
        hairs[before[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> after[i];
        hairs[after[i]]--;
    }
    int a, b;
    for (int i = 0; i <= 1000; i++) {
        if (hairs[i] == 1) a = i;
        else if (hairs[i] == -1) b = i;
    }
    cout << b << "\n";
    cout << a << "\n";
}