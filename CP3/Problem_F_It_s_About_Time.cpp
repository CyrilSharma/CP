#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
int main() {
    int r, s, h;
    cin >> r >> s >> h;
    double days = (M_PI * 2 * r) / (s * h);
    double year = round(days);
    double alpha = abs(year - days);
    int n1=0, n2=0, n3=0;
    double close = -1;
    for (int i = 2; i <= 250; i++) {
        for (int j = 2; j <= (500 / i); j++) {
            for (int k = 2; k <= (1000 / (i * j)); k++) {
                double cur = (1.0/i) - (1.0/(i*j)) + (1.0/(i*j*k));
                if (abs(cur - alpha) < abs(close - alpha)) {
                    close = cur;
                    n1 = i, n2 = i*j, n3 = i*j*k;
                }
            }
        }
    }
    cout<<n1<<" "<<n2<<" "<<n3<<endl;
}