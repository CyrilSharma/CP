/*
ID: cyrilsh1
TASK: zerosum
LANG: C++       
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<string> solutions;
int equation[10];

string numToSym(int i) {
    if (i == 1) return "+";
    if (i == 2) return "-";
    if (i == 3) return " ";
    return "";
}

int eval() {
    int sum = 0;
    int num, count;
    for (int i = 0; i < N; i++) {
        count = 0;
        if (equation[i+1] == 3) {
            num = i+1;
            while (equation[i+count+1] == 3) {
                num = num * 10 + (i + count + 2);
                count++;
            }
        }
        else num = i+1;
        if (equation[i] == 2) sum -= num;
        else if (equation[i] == 1) sum += num;
        i += count;
    }
    return sum;
}

void search(int counter) {
    if (counter == N) {
        if (eval() != 0) return;
        string s = "";
        for (int i = 0; i < N; i++) s += to_string(i+1) + numToSym(equation[i+1]);
        // cout << s << " || " << eval() << "\n";
        solutions.push_back(s);
        return;
    }

    for (int i = 1; i < 4; i++) {
        equation[counter] = i;
        search(counter+1);
        equation[counter] = 0;
    }
}

int main() {
    FILE* fin = fopen("zerosum.in", "r");
    FILE* fout = fopen("zerosum.out", "w");
    fscanf (fin, "%d\n", &N);
    // first term always positive.
    equation[0] = 1; search(1);
    sort(solutions.begin(), solutions.end());
    for (int i = 0; i < solutions.size(); i++) fprintf (fout, "%s\n", solutions[i].c_str());
    return 0;
}
