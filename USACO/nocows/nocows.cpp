/*
ID: cyrilsh1
TASK: nocows
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


int N, K;
long long answers[201][101];

int main() {
    FILE* fin = fopen("nocows.in", "r");
    FILE* fout = fopen("nocows.out", "w");
    fscanf (fin, "%d %d\n", &N, &K);
    for (int i = 1; i <= K; i++) answers[1][i] = 1;
    cout << "    ";
    for (int i = 3; i <= N; i+=2) cout << i << " ";
    cout << "\n";
    for (int j = 2; j <= K; j++) {
        cout << j << " | ";
        for (int i = 3; i <= N; i+=2) {
            for (int k = 1; k <= i-2; k+=2) {
                answers[i][j] = (answers[i][j] + (answers[k][j-1] * answers[i - k - 1][j-1] % 9901)) % 9901;
            } 
            // cout << setfill(' ') << setw(1 + i/5) << answers[i][j] % 9901 << " ";
        }
        cout << "\n";
    }
    fprintf (fout, "%lld\n", (9901 + answers[N][K]-answers[N][K-1]) % 9901);
    return 0;
}
