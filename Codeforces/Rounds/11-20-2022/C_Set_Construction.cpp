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
        vector<int> count(n+1);
        vector<vector<int>> parents(n+1, vector<int>());
        vector<vector<int>> children(n+1, vector<int>());
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char b; cin >> b;
                if (b=='0') continue;
                count[j]++;
                parents[j].push_back(i);
                children[i].push_back(j);
            }
        }

        int tot = 0;
        queue<int> q;
        vector<set<int>> nums(n+1, set<int>());
        for (int i = 1; i <= n; i++) {
            if (count[i] == 0) {
                q.push(i);
            }
        }
        
        while (q.size() != 0) {
            auto node = q.front(); q.pop();
            // merge the sets.
            int largest = -1;
            for (auto parent: parents[node]) {
                largest = max(largest, (int)nums[parent].size());
                for (auto el: nums[parent])
                    nums[node].insert(el);
            }
            nums[node].insert(++tot);
            for (auto child: children[node]) {
                count[child]--;
                if (count[child] == 0) {
                    q.push(child);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout<<nums[i].size()<<" ";
            for (auto el: nums[i]) {
                cout<<el<<" ";
            }
            cout<<"\n";
        }
    }
}