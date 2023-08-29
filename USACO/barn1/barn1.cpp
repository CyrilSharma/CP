/*
ID: cyrilsh1
TASK: barn1
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int compare(const void* a, const void* b) {
    int* A = (int*)(a);
    int* B = (int*)(b);
    return *A - *B;
}

int main() {
    int m,s,c = 0;
    FILE* fin = fopen("barn1.in", "r");
    fscanf (fin, "%d %d %d\n", &m, &s, &c);

    int stalls[c];
    for (int i = 0; i < c; i++)
        fscanf (fin, "%d\n", &stalls[i]);

    qsort(stalls, c, sizeof(int), compare);

    int init = stalls[0];
    int prev = stalls[0];
    int gaps[c-1];
    int curr;   
    for (int i = 1; i < c; i++) {
        curr = stalls[i];
        gaps[i-1] = curr - prev - 1;
        prev = stalls[i];
    }

    int total = curr - init + 1;
    qsort(gaps, c-1, sizeof(int), compare);

    for (int i = 0; i < c-1; i++)
        std::cout << gaps[i] << "\n";

    int gapSum = 0;
    for (int i = (c-1)-1; i >= max((c-1) - (m-1), 0); i--) {
        gapSum += gaps[i];
    }

    FILE* fout = fopen("barn1.out", "w");
    fprintf (fout, "%d\n", total - gapSum);
    return 0;
}
