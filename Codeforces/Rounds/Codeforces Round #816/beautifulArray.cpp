#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;

void findAns(ll n, ll k, ll b, ll s) {
    if (n == 0) { printf("%d\n", -1); return; }
    if ((k * b) > s) { printf("%d\n", -1); return; }
    if (s > (k * b + ((k - 1) * (n - 1)))) { printf("%d\n", -1); return; }
    if ((n-1) == 0) { printf("%d\n", -1); return; }
    
    ll first = k * b;
    ll numLeft = (s - first) % (n - 1);
    ll numPerEntry = (s - first) / (n - 1);
    ll numIters = (numPerEntry == 0) ? n : numLeft;
    printf("%lld ", first);
    for (int i = 0; i < numIters; i++) {
        if (numLeft != 0) {
            printf(" %lld", numPerEntry + 1);
            numLeft -= 1;
        }
        else printf(" %lld", numPerEntry);
    }
    printf("%c", '\n');
    return;
}

int main() {
    int numTests; scanf("%d\n", &numTests);
    ll n, k, b, s;
    for (int i = 0; i < numTests; i++) {
        scanf("%lld %lld %lld %lld", &n, &k, &b, &s);
        findAns(n,k,b,s);
    }
}