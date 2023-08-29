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

int main() {
    fastio
    int n, a, b;
    cin >> n >> a >> b;
    if (n==1) {
        cout<<(a==b)<<endl;
        cout<<a<<":"<<b<<endl;
    } else if (n==2) {
        cout<<0<<endl;
        cout<<a<<":"<<0<<endl;
        cout<<0<<":"<<b<<endl;
    } else if (a+b<n) {
        cout<<n-(a+b)<<endl;
        for (int i=0; i<n-(a+b); i++) cout<<0<<":"<<0<<endl;
        for (int i=0; i<a; i++) cout<<1<<":"<<0<<endl;
        for (int i=0; i<b; i++) cout<<0<<":"<<1<<endl;
    } else if (a+b==n) {
        cout<<0<<endl;
        for (int i=0; i<a; i++) cout<<1<<":"<<0<<endl;
        for (int i=0; i<b; i++) cout<<0<<":"<<1<<endl;
    } else if (a+b>n) {
        int da=0; int db=0;
        for (int i=0; i<a; i++) cout<<1<<":"<<0<<endl;
        for (int i=0; i<b; i++) cout<<0<<":"<<1<<endl;
    }
}
/**
 * @brief idrk know the trick for the last test case :/.
 */