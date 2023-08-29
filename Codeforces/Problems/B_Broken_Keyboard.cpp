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
        int n; cin >> n;
        string s; cin >> s;
        bool valid=true;
        bool key=0;
        for (int i = 0; i < n; i++) {
            if (key) {
                if (i+1==n) valid=false;
                else valid=(s[i]==s[i+1]);
                if (!valid) break;
                i++;
            }
            key=!key;
        }
        if (valid) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}