// UNSOLVED.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int mod = 998244353;
    // compute number of ambiguous arrays.
    // which arrays can be removed?
    // all arrays have one breakdown,
    // which arrays have a second?
    // if you have one odd element you're removable.
    // if you have one element / by smnth 1...n you're ambiguous.
    // if i can kick out elements to my left, only then is there hope i may be removed.
    // dp with array size build array to length n.    
    // all array of size k are built from arrays of size k-1.
    // Two possibilities.
    /**
     * 1. The new term adds ambiguity, use (non-ambiguous + ambiguous) * num
     * 2. The new term doesn't add ambiguity use (ambiguous) * num
     */
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    vector<ll> namb(n); namb[0] = m;
    vector<ll> amb(n);
    for (ll i = 1; i < n; i++) {
        // find number of elements with no factors 1 : i;
    }
}