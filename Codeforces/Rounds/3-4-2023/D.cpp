#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
using ll = long long;
using vi = vector<int>;

int main() {
    // Minimize maximum possible distance.
    // minimize the size of the sphere needed to contain everything.
    // binary search on the size of the sphere.
    // position of the sphere...
    // to find a circle, find the three points with maximal distance from each other?
    // 
    int N, K;
    cin >> N > K;
    vi dist(N);
    for (int i = 0; i < N; i++) {
        cin >> dist[i];
    }
}