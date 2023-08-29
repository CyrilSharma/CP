#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using mint = modint998244353;

int main() {
    int N, A;
    cin >> N >> A;
    mint cur = 1;
    vector<mint> p(N+1), g;
    for (int i = 0; i <= min(A, N); i++) {
        p[i] = cur;
        cur *= (A-i);
        cur /= (i+1);
    }

    auto calc = [&](int c) {
        mint ans = 0;
        for (int i = 0; i < g.size(); i++) {
            //cerr<<(c-i)<<" "<<i<<endl;
            ans += (p[c - i] * g[i]);
        }
        return ans;
    };

    int sum = 0;
    for (int i = 2; i < N; i++) {
        while (g.size() < 1000 && i < N) {
            if (g.size() == 0) {
                g.push_back(1);
                //dbg(p[i-1].val());
                assert(p[i-1] != 0);
                g.push_back(p[i-1]);
            } else {
                vector<mint> temp = {1, calc(i-1)};
                assert(temp[1] != 0);
                g = convolution(g, temp);
            }
            i++;
        }
        sum += g.size();
        dbg(sum)
        // dbg(g[0].val())
        // dbg(g[1].val())
        p = convolution(p, g);
        p.resize(N+1);
        /* for (int j = 0; j <= i; j++)
            assert(p[j] != 0); */
        g.resize(0);
    }
    for (int i = N; i>= 0; i--) {
        if (p[i] != 0) {
            dbg(i);
            break;
        }
    }
    cout<<p[N].val()<<endl;
}
// O(N/d * d * dlog(d)) = O(Ndlog(d))
// O(N/d * (N + d)log(d)) = O(N^2/d * log(d) + Nlog(d)) => O(N^1.5 + Nlog(d))
// d= sqrt(N)/log(N)