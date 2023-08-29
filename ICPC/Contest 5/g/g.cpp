#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p;
    cin >> n;
    string s;
    getline(cin, s);
    vector<int> qs(501);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream iss(s);
        iss >> p;
        qs[p]++;
    }
    for (int i = 100; i <= 500; i+=100) {
        cout << qs[i] << " ";
    }
}