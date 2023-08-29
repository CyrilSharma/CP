/*
ID: cyrilsh1
TASK: prefix
LANG: C++       
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define maxPrimitives 200
#define maxS 200000

string primitives[maxPrimitives];
int numPrimitives = 0;
string S;

int DP[maxS+1];
int main() {
    FILE* fin = fopen("prefix.in", "r");
    FILE* fout = fopen("prefix.out", "w");
    char temp[11];
    while (temp[0] != '.') {
        fscanf (fin, "%s ", temp);
        if (temp[0] == '.') break;
        primitives[numPrimitives] = string(temp);
        numPrimitives++;
    }
    S = "";
    char substring[76];
    while (fscanf (fin, "%s ", substring) != EOF) {
        S += string(substring);
    }

    bool valid;
    DP[0] = 1;
    for (int pos = 0; pos < S.size()+1; pos++) {
        if (DP[pos] != 1) continue;
        for (int j = 0; j < numPrimitives; j++) {
            valid = true;
            for (int k = 0; k < primitives[j].size(); k++) {
                if (primitives[j][k] != S[pos + k]) {
                    valid = false;
                    break;
                }
            }
            if (valid) DP[pos + primitives[j].size()] = 1;
        }
    }
    for (int i = S.size(); i >= 0; i--) {
        if (DP[i] == 1) {
            fprintf (fout, "%d\n", i);
            break;
        }
    }
    return 0;
}
