/*
ID: cyrilsh1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string comet;
    string team;

    std::ifstream infile("ride.in");
    std::getline(infile, comet);
    std::getline(infile, team);

    int mul1 = 1;
    int mul2 = 1;
    int mulValue = 1;
    
    for (int i = 0; i < comet.length(); i++) {
        mul1 *= comet[i] - 'A' + 1;
    }
    for (int i = 0; i < team.length(); i++) {
        mul2 *= team[i] - 'A' + 1;
    }

    int result = mul1 % 47 == mul2 % 47 ? 1 : 0;
    FILE * pFile = fopen ("ride.out","w");
    if (result == 1) {
        fprintf (pFile, "%s", (char*)"GO\n");
    }
    else {
        fprintf (pFile, "%s", (char*)"STAY\n");
    }
    fclose (pFile);
}