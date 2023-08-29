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
        vi p(n); 
        for (auto &pi: p) cin >> pi;
        vi asc(p), des(p);
        sort(asc.begin(), asc.end());
        sort(des.begin(), des.end(), greater<int>());
        int a=0, b=0, c=0;
        for (int i=0; i < n; i++) {
            if (p[i] != asc[i] && p[i] != des[i]) c++;
            else if (p[i] != asc[i]) a++;
            else if (p[i] != des[i]) b++;
        }
        if (a+c<=b) cout<<"First"<<endl;
        else if (b+c<a) cout<<"Second"<<endl;
        else cout<<"Tie"<<endl;
    }
}