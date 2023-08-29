/*
ID: cyrilsh1
TASK: concom
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define COMPS 100

int N;
int stakes[COMPS][COMPS];
int owned[COMPS][COMPS];

void floodfill(int comp) {
    int total_stakes[COMPS];
    for (int i = 0; i < COMPS; i++) total_stakes[i] = 0;

    queue<int> process;
    process.push(comp); owned[comp][comp] = 1;

    int index;
    while (process.size() != 0) {
        index = process.front(); process.pop();
        for (int i = 0; i < COMPS; i++) {
            total_stakes[i] += stakes[index][i];
            if (total_stakes[i] > 50 && !owned[comp][i]) {
                process.push(i);
                owned[comp][i] = 1;
            }
        }
    }
}

int main() {
    FILE* fin = fopen("concom.in", "r");
    FILE* fout = fopen("concom.out", "w");
    fscanf (fin, "%d\n", &N);
    int first, second, stake;
    for (int i = 0; i < N; i++) {
        fscanf (fin, "%d %d %d\n", &first, &second, &stake);
        stakes[first-1][second-1] = stake;
    }
    for (int i = 0; i < COMPS; i++) floodfill(i);
    for (int i = 0; i < COMPS; i++) {
        for (int j = 0; j < COMPS; j++) {
            if (owned[i][j] == 1 && i != j) fprintf (fout, "%d %d\n", i+1, j+1);
        }
    }
    return 0;
}