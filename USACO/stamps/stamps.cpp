/*
ID: cyrilsh1
TASK: stamps
LANG: C++       
*/
#include <iostream>
using namespace std;

int main() {
    int K, N;
    FILE* fin = fopen ("stamps.in", "r");
    fscanf (fin, "%d %d\n", &K, &N);
    int max = K * 10000 + 1;
    int DP[max];
    int val;
    for (int i = 0; i < N; i++) {
        fscanf (fin, "%d ", &val);
        for (int j = 0; j < max; j++) {
            if (i == 0) DP[j] = (j % val == 0) ? j / val : 1e6;
            if (j >= val) DP[j] = min(DP[j-val] + 1, DP[j]);
        }
    }
    FILE* fout = fopen ("stamps.out", "w");
    for (int i = 0; i < max; i++) {
        if (DP[i] > K) {
            fprintf (fout, "%d\n", i-1);
            break;
        }
    }
    return 0;
}
