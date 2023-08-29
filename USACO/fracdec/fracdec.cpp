/*
ID: cyrilsh1
TASK: fracdec
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

int N, D;

void calc() {
    FILE* fout = fopen("fracdec.out", "w");

    int rems[D+1];
    for (int i = 0; i < D+1; i++) {
        rems[i] = -1;
    }
    string num_str = "";

    int num = N;
    int div = num / D;
    int rem = num % D;

    if (div > 0) num_str += to_string(div) + ".";
    else num_str += "0.";
    int begin_size = (int) num_str.size();

    if (rem == 0) {
        fprintf(fout, "%s\n", (num_str + "0").c_str());
        return;
    }

    int i = 0;
    while (rems[rem] == -1 && rem != 0) {
        rems[rem] = i;
        num = rem * 10;
        div = num / D;
        rem = num % D;
        num_str += to_string(div);
        i += 1;
    }
    if (rem != 0) {
        num_str = num_str.substr(0, begin_size + rems[rem]) + "(" + num_str.substr(begin_size + rems[rem], num_str.size()) + ")";
    }
    for (int i = 0; i < 1 + (num_str.size() / 76); i++) {
        for (int j = 0; j < 76; j++) {
            if (76 * i + j < num_str.size())
                fprintf(fout, "%c", num_str[76 * i + j]);
        }
        fprintf(fout, "%c", '\n');
    }
}

int main() {
    FILE* fin = fopen("fracdec.in", "r");
    fscanf (fin, "%d %d", &N, &D);
    calc();
    return 0;
}
