#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int N, Q; cin >> N >> Q;
    using ll = long long;

    int W = 200;
    vector<vector<ll>> cache(W + 1);
    for (int i = 1; i <= W; i++) {
        cache[i].resize(i);
    }

    vector<int> array(N + 1);
    auto answer = [&](int D) {
        ll sum = array[D];
        for (int B = 1; B <= W; B++) {
            sum += cache[B][D%B];
        }
        return sum;
    };

    auto push = [&](tuple<int,int,int> in) {
        auto [A, B, C] = in;
        for (int i = A; i <= N; i += B) {
            if (i == 0) continue;
            array[i] += C;
        }
    };

    for (int i = 0; i < Q; i++) {
        int T; cin >> T;
        if (T == 1) {
            int A, B, C;
            cin >> A >> B >> C;
            if (B > W) push({A, B, C});
            else cache[B][A] += C;
        } else {
            int D; cin >> D;
            cout<<answer(D)<<"\n";
        }
    }
}