#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        vvi mat(2, vi(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> mat[i][j];
            }
        }
        auto check = [&]() {
            for (int i = 0; i < 2; i++) {
                if (mat[i][0] >= mat[i][1]) return false;
            }

            for (int j = 0; j < 2; j++) {
                if (mat[0][j] >= mat[1][j]) return false;
            }
            return true;
        };
        bool possible = false;
        for (int i = 0; i < 4; i++) {
            if (check()) possible=true;
            vvi nmat(mat);
            mat[0][0] = nmat[1][0];
            mat[0][1] = nmat[0][0];
            mat[1][1] = nmat[0][1];
            mat[1][0] = nmat[1][1];
        }
        if (possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}