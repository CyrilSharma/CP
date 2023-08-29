/*
ID: cyrilsh1
TASK: numtri
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

#define maxRows 1000

int R;
int rows[maxRows][maxRows];

int sums[2][maxRows];
int search() {
    sums[1][0] = rows[0][0];
    int counter = 0; int flippedCounter = 1;
    for (int row = 1; row < R; row++) {
        for (int i = 0; i < row+1; i++) {
            if (i == 0) {
                sums[counter][0] = rows[row][0] + sums[flippedCounter][0];
            }
            else if (i == row) {
                // can get rid of special condition if you realize the next index will just be a zero.
                // also learn how to use memMove, gets ride of all this wack counter and flippedCounter business.
                // also you don't have to store it in an array in advance, just iteratively read in the numbers and perform this operation...
                sums[counter][row] = rows[row][row] + sums[flippedCounter][row-1];
            }
            else {
                sums[counter][i] = rows[row][i] + max(sums[flippedCounter][i-1], sums[flippedCounter][i]);
            }
        }
        counter = counter == 0 ? 1 : 0;
        flippedCounter = flippedCounter == 0 ? 1 : 0;
    }
    int maxSum = -1;
    for (int i = 0; i < R; i++) {
        if (sums[flippedCounter][i] > maxSum) maxSum = sums[flippedCounter][i];
    }
    return maxSum;
}


int main() {
    FILE* fin = fopen ("numtri.in", "r");
    FILE* fout = fopen ("numtri.out", "w");

    fscanf (fin, "%d\n", &R);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < i; j++) {
            fscanf (fin, "%d ", &rows[i][j]);
        }
        fscanf (fin, "%d\n", &rows[i][i]);
    }

    int maxSum = search();
    fprintf (fout, "%d\n", maxSum);
    return 0;
}
