#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
using ll = long long;
using vi = vector<int>;

int main() {
    // each number is associated with some K.
    // k0, k0, k1, k1, k1, k2, k2, k3, k3, k4
    int N, K;
    cin >> N > K;
    vi dist(N);
    for (int i = 0; i < N; i++) {
        cin >> dist[i];
    }
}