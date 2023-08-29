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

string operator | (const string& a, const string& b) {
    int sz = min(a.size(), b.size());
    string ans = (a.size() > b.size()) ? a : b;
    for (int i = 0; i < sz; i++) {
        if (a[a.size()-i-1] == '1' || b[b.size()-i-1] == '1') 
            ans[ans.size()-i-1] = '1';
    }
    return ans;
}

string strip(const string& a) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '0') break;
        cnt++;
    }
    if (cnt == a.size()) return "0";
    return a.substr(cnt, string::npos);
}

int main() {
    fastio
    int n; cin >> n;
    string s; cin >> s;
    s = strip(s);
    int pos0 = s.find('0');
    string best = s;
    for (int i = 0; i <= pos0; i++) {
        string cur = s.substr(i, s.size() - pos0);
        string prod = cur | s;
        if (prod > best) best = prod;
    }
    cout<<best<<endl;
}