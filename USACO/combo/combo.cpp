/*
ID: cyrilsh1
TASK: combo
LANG: C++       
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    FILE* fin = fopen("combo.in", "r");
    FILE* fout = fopen("combo.out", "w");

    int n;
    int fCombo[3];
    int mCombo[3];
    fscanf (fin, "%d\n", &n);
    fscanf (fin, "%d %d %d\n", &fCombo[0], &fCombo[1], &fCombo[2]);
    fscanf (fin, "%d %d %d\n", &mCombo[0], &mCombo[1], &mCombo[2]);

    int totalValid;
    if (n > 5)
        totalValid = 250;
    else
        totalValid = 2 * pow(n, 3);
    
    int dist = min(5, n);

    int difference;
    int totalInvalid = 1;
    for (int i = 0; i < 3; i++) {
        difference = (n + fCombo[i] - mCombo[i]) % n;
        difference = min(difference, n - difference);
        if (difference <= 4)
            totalInvalid *= min((5 - difference), dist);
        else
            totalInvalid *= 0;
    }
    fprintf (fout, "%d\n", totalValid - totalInvalid);
    return 0;
}
