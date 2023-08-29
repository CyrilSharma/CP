#include <bits/stdc++.h>
using namespace std;

struct ichar {
  char c;
  int idx;
};

int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ichar> ichars(n);
    for (int i = 0; i < n; i++) {
      ichars[i] = { s[i], i };
    }
    auto icmp = [](ichar a, ichar b) {
      if (a.c != b.c) return a.c < b.c;
      return a.idx < b.idx;
    };
    sort(ichars.begin(), ichars.end(), icmp);
    int len = (k%2 == 0) ? k - 1 : n;
    cerr<<"len= "<<len<<"\n";
    sort(ichars.begin() + n - len, ichars.end(),
      [](ichar a, ichar b) {
        return a.idx < b.idx;
      }
    );
    /* cerr<<"to-k: ";
    for (int i = 0; i < n; i++)
      cerr<<ichars[i].c;
    cerr<<"\n"; */

    vector<char> left, right;
    for (int i = n - len; i < n; i++) {
      if (i%2) left.push_back(ichars[i].c);
      else     right.push_back(ichars[i].c);
    }
    /* for (char c: left) cerr<<c; cerr<<endl;
    for (char c: right) cerr<<c; cerr<<endl;
    continue; */

    sort(left.begin(),  left.end());
    sort(right.begin(), right.end());
    for (int i = 0; i < n - len; i++) {
      cout<<ichars[i].c;
    }
    int cnt = 0;
    for (int i = n - len; i < n; i++) {
      if (i%2) cout<<left[cnt/2];
      else     cout<<right[cnt/2];
      cnt++;
    }
    cout<<"\n";
  }
}