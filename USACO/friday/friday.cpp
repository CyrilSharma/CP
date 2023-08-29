/*
ID: cyrilsh1
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    FILE * fin = fopen("friday.in","r");
    int numYears;
    fscanf (fin, "%d", &numYears);

    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    // sat, sun, mon...
    int days[7] = {0,0,0,0,0,0,0};
    int day = 0;
    for (int i = 0; i < numYears; i++) {
        // leap day conditions.
        if ((1900 + i) % 400 == 0) {
            month[1] = 29;
        }
        else if (i % 100 == 0) {
            month[1] = 28;
        }
        else if (i % 4 == 0) {
            month[1] = 29;
        }
        else {
            month[1] = 28;
        }

        // cycle back around
        if (i != 0) {
            day += month[11];
            day = day % 7;
        }

        for (int j = 0; j < 11; j++) {
            days[day] += 1;
            day += month[j];
            day = day % 7;
        }
        days[day] += 1;
    }

    FILE * fout = fopen("friday.out","w");
    for (int i = 0; i < 6; i++) {
        fprintf (fout, "%d ", days[i]);
    }
    fprintf (fout, "%d\n", days[6]);
}
