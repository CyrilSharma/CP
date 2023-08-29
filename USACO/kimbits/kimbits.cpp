/*
ID: cyrilsh1
TASK: kimbits
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

int N, L, I;
int bits[31];

int counter = 0;
void iterate(int lBit, int lPos, int max) {
    if (counter > max) return;
    if (lBit == 0) {
        counter++;
        if (counter == max) {
            int i;
            FILE* fout = fopen ("kimbits.out", "w");
            for (int i = N-1; i >= 0; i--) {
                fprintf (fout, "%d", bits[i]);
            }
            fprintf (fout, "%c", '\n');
        }
        return;
    }
    // lBit -> 1, 2, 3
    for (int i = lBit-1; i < lPos; i++) {
        bits[i] = 1;
        iterate(lBit-1, i, max);
        bits[i] = 0;
    }
}

long long choose(int n, int c) {
    long long mult = 1;
    int start = min(n-c, c);
    for (int i = start+1; i <= n; i++) {
        mult *= i;
        mult /= (i - start);
    }
    return mult;
}

void count() {
    long long total = 0;
    long long increment;
    if (I == 1) {
        iterate(0, 0, 1);
        return;
    }
    for (int len = 1; len <= N; len++) {
        for (int b = 1; b <= min(len, L); b++) {
            increment = choose(len-1, b-1);
            if (total + increment > I) {
                bits[len-1] = 1;
                iterate(b - 1, len - 1, I - total);
                return;
            }
            else total += increment;
        }
    }
}

int main() {
    FILE* fin = fopen ("kimbits.in", "r");
    fscanf (fin, "%d %d %d\n", &N, &L, &I);
    count();
    return 0;
}
