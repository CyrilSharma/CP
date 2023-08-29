/*
ID: cyrilsh1
TASK: subset
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define maxN 39

int N;
int DP[maxN+1][1 + maxN * (maxN+1)/ 4];

int main() {
    FILE* fin = fopen("subset.in", "r");
    FILE* fout = fopen("subset.out", "w");
    fscanf (fin, "%d\n", &N);
    int target;
    if ((N * (N+1)) % 4 == 0) {
        target = N * (N+1) / 4;
    }
    else {
        fprintf (fout, "%d\n", 0);
        return 0;
    }
    DP[1][0] = 1; DP[1][1] = 1;
    for (int i = 2; i < N+1; i++) {
        for (int j = 0; j < target+1 - i; j++) {
            DP[i][j] += DP[i-1][j];
            DP[i][i + j] = DP[i-1][j];
        }
    }
    fprintf (fout, "%d\n", DP[N][target]);
    return 0;
}
