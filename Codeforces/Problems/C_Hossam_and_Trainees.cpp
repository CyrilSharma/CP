//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
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

vi sieve(int N) {
    vi isprime(N, 1);
    isprime[0]=0, isprime[1]=0, isprime[2]=1;
    for (int i=4; i < N; i+=2) isprime[i]=0;
    for (int i=3; i*i < N; i+=2) {
        if (!isprime[i]) continue;
        for (int j=i*i; j < N; j+=(2*i))
            isprime[j]=0;
    }
    return isprime;
}

vi genPrimes(int N) {
    vi ans;
    vi isprime = sieve(N);
    for (int i = 0; i < N; i++) {
        if (!isprime[i]) continue;
        ans.push_back(i);
    }
    return ans;
}

vi primes = genPrimes(1e5);
void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &ai: a) cin >> ai;
    map<int,int> has;
    for (int ai: a) {
        for (auto p: primes) {
            if (p*p > ai) break;
            if (ai%p != 0) continue;
            while (ai%p == 0) ai/=p;
            if (has[p]) {
                cout<<"YES"<<endl;
                return;
            }
            has[p]=1;
        }
        if (ai == 1) continue;
        if (has[ai]) {
            cout<<"YES"<<endl;
            return;
        }
        has[ai]=1;
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio
    int t; cin >> t;
    while (t--) {
        solve();
    }
}