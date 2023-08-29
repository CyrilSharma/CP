#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using vi = vector<int>;
using ll = long long;
int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<int> sortVec = nums;
        sort(sortVec.begin(), sortVec.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (nums[i] == sortVec[0]) cout<<nums[i]-sortVec[1]<<" ";
            else cout<<nums[i]-sortVec[0]<<" ";
        }
        cout<<"\n";
    }
}