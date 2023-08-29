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
    vi nums;
    vvi towers(n, vi());
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int b; cin >> b;
            towers[i].push_back(b);
            nums.push_back(b);
        }
    }
    sort(nums.begin(), nums.end());

    int splits=0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < towers[i].size(); j++) {
            int lb1 = lower_bound(nums.begin(), nums.end(), towers[i][j]) - nums.begin(); 
            int lb2 = lower_bound(nums.begin(), nums.end(), towers[i][j-1]) - nums.begin();
            if (!(lb1 - lb2 == 1 || lb1 == lb2)) splits++;
        }
    }
    cout<<splits<<" "<<(n + splits - 1)<<endl;
}