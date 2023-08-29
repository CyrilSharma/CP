/*
ID: cyrilsh1
TASK: holstein
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

#define maxVitamins 25
#define maxFeeds 15

int V;
int G;
int reqs[maxVitamins];
int feeds[maxFeeds][maxVitamins];

FILE* fout;

int numSolutions = 0;
vector<pair<int, int> > solutions;
int chosenFeeds[maxFeeds];
int sums[maxVitamins];

void search(int depth, int maxDepth, int start) {
    if (numSolutions > 0) return;
    if (maxDepth == depth) return;
    bool valid;
    for (int i = start; i < G; i++) {
        if (chosenFeeds[i] == 1) continue;
        valid = true;
        for (int j = 0; j < V; j++) {
            sums[j] += feeds[i][j];
            if (sums[j] < reqs[j]) valid = false;
        }
        chosenFeeds[i] = 1;
        if (!valid) search(depth+1, maxDepth, i+1);
        else {
            numSolutions++;
            int numFeeds = depth+1;
            fprintf(fout, "%d ", numFeeds);
            for (int j = 0; j < G; j++) {
                if (chosenFeeds[j] != 0) {
                    if (numFeeds != 1) {
                        fprintf(fout, "%d ", j+1);
                        numFeeds--;
                    }
                    else fprintf(fout, "%d\n", j+1);
                }
            }
        } 
        chosenFeeds[i] = 0;
        for (int j = 0; j < V; j++) sums[j] -= feeds[i][j];
    }
}

void DFS() {
    // maximum of 15 feeds allowed.
    for (int i = 1; i < G+1; i++) {
        search(0, i, 0);
        if (numSolutions > 0) break;
    }
}

int main() {
    FILE* fin = fopen("holstein.in", "r");
    fout = fopen("holstein.out", "w");

    fscanf (fin, "%d\n", &V);
    for (int i = 0; i < V; i++) {
        fscanf (fin, "%d\n", &reqs[i]);
    }
    fscanf (fin, "%d\n", &G);
    for (int i = 0; i < G; i++) {
        for (int j = 0; j < V; j++) {
            fscanf (fin, "%d ", &feeds[i][j]);
        }
    }

    DFS();
    return 0;
}
