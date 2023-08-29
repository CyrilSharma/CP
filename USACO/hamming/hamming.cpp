/*
ID: cyrilsh1
TASK: hamming
LANG: C++       
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define maxN 64

int N,B,D;
int numWords = 0;
int codeWords[maxN];
bool solutionFound = false;
FILE* fout;

int countOnes(int a) {
    int count = 0;
    int temp = a;
    while (temp > 0) {
        if (temp % 2 == 1) {
            count++;
            temp -= 1;
        }
        temp /= 2;
    }
    return count;
}

int hammingDistance(int a, int b) {
    int c = a^b;
    return countOnes(c);
}

void search(int start) {
    if (solutionFound) return;
    if (numWords == N) {
        for (int i = 0; i < numWords; i++) {
            if (i % 10 != 9 && i != numWords-1) fprintf (fout, "%d ", codeWords[i]);
            else if (i % 10 == 9) fprintf (fout, "%d\n", codeWords[i]);
            else if (i == numWords-1) fprintf(fout, "%d\n", codeWords[i]);
        }
        solutionFound = true;
        return;
    }
    bool valid;
    for (int i = start+1; i < pow(2, B); i++) {
        valid = true;
        for (int j = 0; j < numWords; j++) {
            if (hammingDistance(codeWords[j], i) < D) valid = false;
        }
        if (!valid) continue;
        codeWords[numWords] = i;
        numWords++;
        search(i);
        numWords--;
        codeWords[numWords] = 0;
    }
    return;
}

int main() {
    FILE* fin = fopen("hamming.in", "r");
    fout = fopen("hamming.out", "w");
    fscanf (fin, "%d %d %d\n", &N, &B, &D);
    codeWords[0] = 0; numWords += 1;
    search(0);
    return 0;
}
