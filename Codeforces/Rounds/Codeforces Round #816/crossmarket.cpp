#include <iostream>
#include <fstream>
using namespace std;

int minEnergy(int m, int n) {
    if (m == 1 && n == 1) return 0;
    if (m == 1) return n;
    if (n == 1) return m;
    return min(m-1, n-1) + (m + n - 1);
}

int main() {
    int numTests; scanf("%d\n", &numTests);
    int m, n;
    for (int i = 0; i < numTests; i++) {
        scanf("%d %d", &m, &n);
        printf("%d\n", minEnergy(m, n));
    }
}