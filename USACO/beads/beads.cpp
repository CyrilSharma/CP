/*
ID: cyrilsh1
TASK: beads
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

char determineScore(string beads, int index) {
    char leftBead = beads[(index)%beads.length()];
    char rightBead = beads[(index+1)%beads.length()];
    int leftLen = 0;
    int rightLen = 0;
    char currentBead;

    // determine left side score
    for (int i = 0; i < beads.length(); i++) {
        currentBead = beads[(beads.length()+index-i)%beads.length()];
        if (leftBead == 'w') {
            if (currentBead != 'w')
                leftBead = currentBead;
            leftLen += 1;
        }
        else {
            if (currentBead == leftBead || currentBead == 'w')
                leftLen += 1;
            else
                break;
        }
    }

    // determine right side score
    for (int i = 0; i < beads.length(); i++) {
        currentBead = beads[(beads.length()+index+1+i)%beads.length()];
        if (rightBead == 'w') {
            if (currentBead != 'w')
                rightBead = currentBead;
            rightLen += 1;
        }
        else {
            if (currentBead == rightBead || currentBead == 'w')
                rightLen += 1;
            else
                break;
        }
    }

    int score = std::min(rightLen + leftLen, (int)beads.length());
    return score;
}

int main() {
    FILE* fin = fopen("beads.in", "r");
    int numBeads;
    fscanf (fin, "%d", &numBeads);

    char buff[numBeads];
    fscanf (fin, "%s", buff);
    // strings are nicer to work with.
    string beads(buff);
    int maxScore = -1;
    int score = 0;
    for (int i = 0; i < numBeads; i++) {
        score = determineScore(beads, i);
        if (score > maxScore) {
            maxScore = score;
        }
    }
    FILE* fout = fopen("beads.out", "w");
    fprintf (fout, "%d\n", maxScore);
}
