/*
ID: cyrilsh1
TASK: ariprog
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

int N;
int M;
set<int> bisquare_set;

int main() {
    FILE* fin = fopen("ariprog.in", "r");
    FILE* fout = fopen("ariprog.out", "w");
    fscanf (fin, "%d\n", &N);
    fscanf (fin, "%d\n", &M);
    
    for (int p = 0; p <= M; p++) {
        for (int q = 0; q <= M; q++) {
            bisquare_set.insert(p*p + q*q);
        }
    }

    int numSolutions = 0;
    pair<int, int> solutions[2 * M * M];

    bool oneSeqFound = false;
    bool validSeq;
    int max = 2 * M * M;
    int a;
    for (int b = 1; b <= max / (N-1); b++) {
        for (int a_init = 0; a_init < b; a_init++) {
            a = a_init;
            while (a <= (max - (N-1)*b)) {
                validSeq=true;
                // if this fails, you need to continue checking at the spot you're at now.
                for (int n = N-1; n >= 0; n--) {
                    if (bisquare_set.count(a + b * n) == 0) {
                        validSeq = false;
                        a = a + b * n + b;
                        break;
                    }
                }

                if (validSeq) { 
                    // always sorts by first index.
                    solutions[numSolutions] = make_pair(b, a);
                    numSolutions += 1;
                    a += b;
                }
            }
        }
    }
    sort(solutions, solutions + numSolutions);
    if (numSolutions == 0) fprintf (fout, "%s\n", "NONE");
    for (int i = 0; i < numSolutions; i++) {
        fprintf (fout, "%d %d\n", solutions[i].second, solutions[i].first);
    }
    return 0;
}
