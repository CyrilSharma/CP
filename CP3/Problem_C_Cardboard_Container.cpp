#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll V; cin >> V;
    vector<ll> factors;
    for (int i = 1; i <= V; i++)
        if ((V%i) == 0) factors.push_back(i);
    
    ll best = 1e18;
    for (ll f: factors) {
        for (ll g: factors) {
            if (V % (f * g)) continue;
            ll h = V / (f * g);
            best = min(best, 2*(f*g + g*h + h*f));
        }
    }
    cout<<best<<"\n";
}