/*
ID: cyrilsh1
TASK: skidesign
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_HEIGHT 100
int N;

int main() {
    FILE* fin = fopen ("skidesign.in", "r");
    FILE* fout = fopen ("skidesign.out", "w");
    fscanf (fin, "%d\n", &N);
    int elevations[N];
    for (int i = 0; i < N; i++) fscanf (fin, "%d\n", &elevations[i]);

    int cost;
    int minCost = pow(1000, 3);
    for (int i = 0; i < MAX_HEIGHT-17; i++) {
        cost = 0;
        for (int j = 0; j < N; j++) {
            if (elevations[j] < i) 
                cost += pow((i - elevations[j]), 2);
            else if (elevations[j] > (i+17))
                cost += pow((elevations[j] - (i+17)), 2);
        }
        if (cost < minCost) minCost = cost;
    }
    fprintf (fout, "%d\n", minCost);
    return 0;
}
