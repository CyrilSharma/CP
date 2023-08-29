#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int q; cin >> q;
        using ll = long long;
        bool otherS = false; bool otherT = false;
        ll cntS = 0; ll cntT = 0;
        for (int i = 0; i < q; i++) {
            ll d, k; string x;
            cin >> d >> k >> x;
            for (char c: x) {
                if (d == 1) {
                    if (c != 'a') otherS = 1;
                    else cntS += k;
                } else {
                    if (c != 'a') otherT = 1;
                    else cntT += k;
                }
            }
            bool status = 0;
            if (otherT) status = 1;
            else if (!otherS && cntS < cntT) status = 1;
            else status = 0;
            cout<<(status ? "YES" : "NO")<<"\n";
        }
    }
}
/**
 * Lot's of stupid mistakes.
 * 1. Didn't realize the purpose of making the first character a.
 * If they give you implementation details, and you don't know the signifigance,
 * You should probably figure that out...
 * Misinterpreted the entire problem. Read the test cases so you don't burn time.
 * Didn't read the editorial fast enough. You spent so much time making such dumb mistakes,
 * you should've been able to admit you didn't know the right approach and concede.
 */