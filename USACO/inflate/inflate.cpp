/*
ID: cyrilsh1
TASK: inflate
LANG: C++       
*/
#include <iostream>
using namespace std;

int main() {
    FILE* fin = fopen ("inflate.in", "r");
    int i, j, p, t, M, N;
    fscanf (fin, "%d %d", &M, &N);
    int DP[M+1];
    for (i = 0; i < N; i++) {
        fscanf (fin, "%d %d\n", &p, &t);
        for (j = 0; j <= M; j++) {
            if (i == 0)
                DP[j] = p * (j / t);
            else if (j >= t)
                DP[j] = max(DP[j], DP[j-t] + p);
        }
    }
    FILE* fout = fopen("inflate.out", "w");
    fprintf (fout, "%d\n", DP[M]);
    return 0;
}