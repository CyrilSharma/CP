/*
ID: cyrilsh1
TASK: frac1
LANG: C++       
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define maxN 160

int N;
vector<pair<double, pair<int, int> > > results;
int visited[maxN+1][maxN+1];

int main() {
    FILE* fin = fopen("frac1.in", "r");
    FILE* fout = fopen("frac1.out", "w");

    fscanf (fin, "%d\n", &N);

    int factor;
    int numResults = 1;
    results.push_back(make_pair(0, make_pair(0, 1)));
    for (int den = 1; den < N+1; den++) {
        for (int num = 1; num <= den; num++) {
            factor = 1;
            for (int k = 2; k <= den/2; k++) {
                if (num%k == 0 && den%k == 0) factor = k;
            }
            if (num == den) factor = den;
            if (visited[num/factor][den/factor] == 0) {
                visited[num/factor][den/factor] = 1;
                results.push_back(make_pair((double)num/(double)den, make_pair(num, den)));
                numResults += 1;
            }
        }
    }

    sort(results.begin(), results.end());
    for (int i = 0; i < numResults; i++) {
        fprintf (fout, "%d/%d\n", results[i].second.first, results[i].second.second);
    }
    return 0;
}
