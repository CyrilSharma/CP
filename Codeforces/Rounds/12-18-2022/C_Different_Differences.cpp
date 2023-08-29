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
        int k, n;
        cin >> k >> n;
        
        cout<<1<<" ";
        int sum=0; int prev=1; int diff=1;
        for (int i = 2; i <= k; i++) {
            sum += diff; diff++; 
            if (sum <= (n-k)) cout<<prev+diff<<" ";
            else diff=1, cout<<prev+diff<<" ";
            prev += diff;
        }
        cout<<endl;
    }
}