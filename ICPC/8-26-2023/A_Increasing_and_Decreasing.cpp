#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while (t--) {
    int x, y, n;
    cin >> x >> y >> n;
    auto mn = [&](int start) {
      return (start + (n - 2) * (n - 1) / 2);
    };
    cerr<<"mn(10): "<<mn(10)<<"\n";
    int start = -1;
    for (int i = n - 1; i <= 1000; i++) {
      if (x + mn(i) < y) continue;
      start = i;
      break;
    }
    if (start == -1) {
      cout<<"-1\n";
    } else {
      cout<<x<<" ";
      cout<<x+start<<" ";
      int acc = x + start;
      for (int i = n - 3; i >= 1; i--) {
        acc += i;
        cout<<acc<<" ";
      }
      cout<<y<<" ";
      cout<<"\n";
    }
  }
}