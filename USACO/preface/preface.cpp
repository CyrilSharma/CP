/*
ID: cyrilsh1
TASK: preface
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int N;
// I,V,X,L,C,D,M, extra char.
int counters[8];
int counts10[10][3] = {{0,0,0}, {1,0,0}, {2,0,0}, {3,0,0}, {1,1,0}, {0,1,0}, {1,1,0}, {2,1,0}, {3,1,0}, {1,0,1}};

void count(int n) {
    if (n / 10 == 0) {
        for (int i = 0; i < 3; i++) {
            counters[i] += counts10[n][i];
        }
        return;
    }
    string num = to_string(n);
    int scale = pow(10, num.size()-1);
    int digit = (n / scale);
    for (int i = 0; i < 3; i++) {
        counters[2*(num.size()-1) + i] += counts10[digit][i];
    }
    count(n - digit * scale);
}

int main() {
    FILE* fin = fopen("preface.in", "r");
    FILE* fout = fopen("preface.out", "w");
    fscanf (fin, "%d\n", &N);
    string symbols[8] = {"I", "V", "X", "L", "C", "D", "M", "WRONG"};
    for (int i = 0; i < N+1; i++) count(i);
    // count(1999);
    for (int i = 0; i < 8; i++) {
        if (counters[i] != 0) {
            fprintf (fout, "%s %d\n", symbols[i].c_str(), counters[i]);
        }
    } 
    return 0;
}
