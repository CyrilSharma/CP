/*
ID: cyrilsh1
TASK: sprime
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

FILE* fout;
int N;

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void search(int num, int counter) {
    if (!isPrime(num) && counter != 0) return;

    if (counter == N) {
        fprintf (fout, "%d\n", num);
        return;
    }
    
    for (int i = 1; i < 10; i++) {
        if (counter == 0) {
            if (i != 2 && (i%2 == 0 || i == 1)) continue;
        }
        else if (i%2 == 0 || i==5) continue;
        num = num * 10 + i;
        search(num, counter+1);
        num = (num - i) / 10;
    }
}

int main() {
    FILE* fin = fopen("sprime.in", "r");
    fout = fopen("sprime.out", "w");
    fscanf (fin, "%d\n", &N);
    search(0,0);
    return 0;
}
