#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

int main() {
    //fastio
    int n; cin >> n;
    vvll board(n, vll(n));
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            tot += board[i][j];
        }
    }
    ll least = 1e18;
    for (int i = 0; i < n; i++) {
        least=min(least,board[i][n-i-1]);
    }
    printf("%lld\n", tot-least);
}