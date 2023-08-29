/*
ID: cyrilsh1
TASK: lamps
LANG: C++       
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 100

int N, C;
int config[maxN+1];
int last[maxN+1];
vector<string> solutions;
FILE* fout;

bool valid() {
    for (int i = 1; i < N+1; i++) {
        if (last[i] != 2 && config[i] != last[i]) return false;
    }
    return true;
}

void flipEven() {
    for (int i = 2; i < N+1; i+=2) config[i] ^= 1;
}

void flipOdd() {
    for (int i = 1; i < N+1; i+=2) config[i] ^= 1;
}

void flipAll() {
    for (int i = 1; i < N+1; i++) config[i] ^= 1;
}

void flip3k() {
    for (int i = 1; i < N+1; i+=3) config[i] ^= 1;
}

void flipSwitch(int i) {
    if (i == 0) flipEven();
    else if (i == 1) flip3k();
    else if (i == 2) flipOdd();
    else if (i == 3) flipAll();
}
// figure out how to sort these...
void check(int counter, int flipped) {
    if (counter == 4) {
        if (flipped > C) return;
        if (C%2 != flipped%2) return;
        else if (valid()) {
            string sol = "";
            for (int i = 1; i < N+1; i++) sol+=to_string(config[i]);
            solutions.push_back(sol);
        }
        return;
    }
    for (int i = 0; i < 2; i++) {
        if (i) flipSwitch(counter);
        check(counter+1, flipped+i); 
        if (i) flipSwitch(counter);
    }
}

int main() {
    FILE* fin = fopen("lamps.in", "r");
    fout = fopen("lamps.out", "w");
    fscanf (fin, "%d\n", &N);
    fscanf (fin, "%d\n", &C);
    for (int i = 1; i < N+1; i++) last[i] = 2;
    int num = 0;
    while (num != -1) {
        fscanf (fin, "%d ", &num);
        if (num != -1) last[num] = 1;
    }
    num = 0;
    while (num != -1) {
        fscanf (fin, "%d ", &num);
        if (num != -1) last[num] = 0;
        else last[num] = -1;
    }
    for (int i = 1; i < N+1; i++) config[i] = 1;
    check(0, 0);
    sort(solutions.begin(), solutions.end());
    if (!solutions.size()) fprintf (fout, "%s\n", "IMPOSSIBLE");
    for (int i = 0; i < solutions.size(); i++) {
        fprintf (fout, "%s\n", solutions[i].c_str());
    }
    return 0;
}
