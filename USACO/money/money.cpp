/*
ID: cyrilsh1
TASK: money
LANG: C++       
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int V, N;
int values[26];
long long DP[26][10001];

int main() {
    // SEEMS LIKE A DP PROBLEM TO ME.
    FILE* fin = fopen("money.in", "r");
    FILE* fout = fopen("money.out", "w");
    fscanf (fin, "%d %d ", &V, &N);
    for (int i = 0; i < V; i++) fscanf (fin, "%d ", &values[i]);
    for (int j = 0; j < N+1; j++) {
        if (j % values[0] == 0) DP[0][j] = 1;
    }
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < N+1; j++) {
            for (int k = 0; k <= j; k += values[i]) {
                DP[i][j] += DP[i-1][j-k];
            }
        }
    }
    fprintf (fout, "%lld\n", DP[V-1][N]);
    return 0;
}
