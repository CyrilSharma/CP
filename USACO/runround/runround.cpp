/*
ID: cyrilsh1
TASK: runround
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

long long M;

bool isRoundNum(long long input) {
    string num = to_string(input);
    int pos = 0;
    for (int i = 0; i < num.size(); i++) {
        for (int j = 0; j < num.size(); j++) {
            if (i == j) continue;
            if (num[j] == num[i]) return false;
        }
    }
    for (int i = 0; i < num.size(); i++) {
        if (pos == 0 && i != 0) return false;
        pos = (pos + (int) (num[pos] - '0')) % num.size();
    }
    if (pos == 0) return true;
    else return false;
}

int main() {
    FILE* fin = fopen("runround.in", "r");
    FILE* fout = fopen("runround.out", "w");
    fscanf (fin, "%lld", &M);
    for (long long i = M+1; i < pow(10, 9); i++) {
        if (isRoundNum(i)) {
            fprintf(fout, "%lld\n", i);
            break;
        }
    }
    return 0;
}
