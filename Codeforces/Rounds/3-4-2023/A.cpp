#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
using ll = long long;
using vi = vector<int>;

int main() {
    int n, k;
    cin >> n >> k;
    // n rocks, remove up to k.
    // suppose k rocks.
    // player 1 wins.
    // suppose k+1 rocks
    // player 2 wins.
    // suppose k+2 rocks
    // player 1 wins.
    // suppose k+3, k+4, k+5... rocks
    // player 1 wins, remove until k+1.
    // p1 only loses when %(k+1) == 0
    cout<<"Adrien"<<endl;
    if ((n)%(k+1)) {
        
    } else {
        cout<<"Austin"<<endl;
    }
}