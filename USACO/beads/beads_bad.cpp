/*
ID: cyrilsh1
TASK: beads
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

char determineBeadColor(string beads, int index) {
    char pastBead = beads[(beads.length()+index-1)%beads.length()];
    char nextBead = beads[(beads.length()+index+1)%beads.length()];
    char latestLeftBead;
    char latestRightBead;
    if (pastBead == nextBead) {
        return pastBead;
    }
    int leftLen = 0;
    int rightLen = 0;

    for (int i = 0; i < beads.length(); i++) {
        latestLeftBead = beads[(beads.length()+index-1-i)%beads.length()];
        if (latestLeftBead == pastBead || latestLeftBead == 'w' || pastBead == 'w') {
            leftLen += 1;
            if (latestLeftBead != 'w') {
                pastBead = latestLeftBead;
            }
        }
        else {
            break;
        }
    }

    for (int i = 0; i < beads.length(); i++) {
        latestRightBead = beads[(beads.length()+index+1+i)%beads.length()];
        if (latestRightBead == nextBead || latestRightBead == 'w' || nextBead == 'w') {
            if (latestRightBead != 'w') {
                nextBead = latestRightBead;
            }
            rightLen += 1;
        }
        else {
            break;
        }
    }

    if (rightLen > leftLen) {
        return nextBead;
    }
    else if (leftLen > rightLen) {
        return pastBead;
    }
    else {
        return nextBead;
    }
}

bool isChunkEnd(string beads, int index) {
    char prevChar = beads[(index - 1 + beads.length()) % beads.length()];
    char startChar = beads[index];
    if (startChar != prevChar) {
        if (startChar != 'w' && prevChar != 'w') {
            return true;
        }
    }
    return false;
}

int findChunkEnd(string beads, int index) {
    string beadsCopy = beads;
    char curChar;
    char nextChar;
    char whiteBeadColor;
    int i;
    int counter = 0;
    while (counter < beads.length()) {
        i = index + counter;
        curChar = beadsCopy[i%beadsCopy.length()];
        nextChar = beadsCopy[(i+1)%beadsCopy.length()];
        // std::cout << curChar << " " << nextChar << "\n";
        if (curChar != nextChar) {
            // neither are white
            if (curChar != 'w' && nextChar != 'w') {
                // std::cout << i << " | " << index << "\n";
                return (i)%beadsCopy.length();
            }

            if (nextChar == 'w') {
                // assign the white char to make a continuous chain with the current one.
                whiteBeadColor = determineBeadColor(beads,(i+1)%beadsCopy.length());
                std::cout << "whitebeadcolor: " << whiteBeadColor << "\n";
                if (curChar != whiteBeadColor && curChar != 'w') {
                    return (i)%beadsCopy.length();
                }
                beadsCopy[(i+1)%beadsCopy.length()] = whiteBeadColor;
            }
        }
        counter += 1;
    }
    return -1;
}

int main() {
    FILE* fin = fopen("beads.in", "r");
    int numBeads;
    fscanf (fin, "%d", &numBeads);

    char buff[numBeads];
    fscanf (fin, "%s", buff);
    // strings are nicer to work with.
    string beads(buff);

    vector<int> ls;
    int counter, initCounter, newCounter = 0;
    if (isChunkEnd(beads, 0)) {
        initCounter = 0;
        counter = 0;
    }
    else {
        initCounter = findChunkEnd(beads, 0);
        counter = initCounter;
    }

    bool justStarted = true;
    // while you've only done one revolution.
    while (counter != initCounter || justStarted) {
        justStarted = false;
        newCounter = findChunkEnd(beads, counter+1);
        std::cout << beads.substr(counter+1, newCounter-counter) << "\n";
        std::cout << "diff: " << (beads.length() + newCounter - counter) % beads.length() << "\n";
        ls.push_back((beads.length() + newCounter - counter) % beads.length());
        counter = newCounter;
    }

    for (int i = 0; i < ls.size(); i++) {
        std::cout << ls[i] << " ";
    }

    int maxSum = -1;
    int sum;
    for (int i = 0; i < ls.size() - 1; i++) {
        sum = ls[i] + ls[i + 1];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    std::cout << "Maximum sum: " << maxSum << "\n";
}
