#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
using ll = long long;
using vi = vector<int>;

int main() {
    int N, K;
    cin >> N >> K;
    string s, t;
    cin >> s >> t;

    int l = 0, r = 0;
    while (l < N) {
        int length = 0;
        while (s[l] == s[r] &&
            r < N && length < K) {
            length++;
            r++;
        }
        if (length == K) {
            cout<<"Yes"<<endl;
            return 0;
        }
        l++;
    }
    if (s == t) {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}