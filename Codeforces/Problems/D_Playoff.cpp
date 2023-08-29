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
    int n; cin >> n;
    string s; cin >> s;
    int a=0, b=0;
    for (char c: s) {
        if (c=='0') b++;
        else a++;
    }
    for (int i = 1<<a; i <= ((1<<n) - (1<<b) + 1); i++) {
        cout<<i<<" ";
    }
}