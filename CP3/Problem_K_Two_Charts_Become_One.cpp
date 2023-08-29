#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

int main() {
    fastio
    mt19937 rng(69420);
    map<ll, ll> rands;
    set<int,int> s;
    map<int,int> m;
    unordered_set<int,int> us;
    unordered_map<int,int> um;
    auto gen = [&](ll a) {
        if (rands.count(a)) {
            return rands[a];
        } else {
            ll mp = uniform_int_distribution<ll>(-1e13, 1e13)(rng);
            rands[a] = mp;
            return mp;
        }
    };
    
    auto make_hashes = [&](string tree) {
        set<ll> hashes;
        stack<ll> stk;
        for (int i = 0; i < tree.size(); i++) {
            bool atnum = false;
            string numstr = "";
            if (tree[i] == ' ') continue;
            while (tree[i] >= '0' && tree[i] <= '9') {
                atnum = true;
                numstr += tree[i];
                i++;
            }
            if (atnum) {
                ll hash = gen(stoll(numstr));
                stk.push(hash);
                hashes.insert(hash);
            }
            if (tree[i] == '(') {
                stk.push(1e18);
            } else if (tree[i] == ')') {
                ll hash = 0;
                while (!stk.empty() && stk.top() != 1e18) {
                    hash += stk.top(); stk.pop();
                }
                if (!stk.empty() && stk.top() == 1e18) {
                    stk.pop();
                }
                stk.push(hash);
                hashes.insert(hash);
            }
        }
        cout<<endl;
        return hashes;
    };
    string tree1 = "(", line1;
    getline(cin, line1); 
    tree1 += (line1 + ")");
    set<ll> hash1 = make_hashes(tree1);

    string tree2 = "(", line2;
    getline(cin, line2); 
    tree2 += (line2 + ")");
    set<ll> hash2 = make_hashes(tree2);

    if (hash1.size() != hash2.size()) {
        cout<<"No"<<endl;
        return 0;
    }
    for (auto h: hash1) {
        if (!hash2.count(h)) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}