/*
ID: cyrilsh1
TASK: agrinet
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

#define maxDist  1e6

int N;
int graph[100][100];

void search() {
    int dist[N];
    int source[N];
    int intree[N];

    for (int i = 0; i < N; i++) {
        intree[i] = 0;
        dist[i] = graph[0][i];
        source[i] = 0;
    }

    int treeSize = 0;
    int treeCost = 0;
    int minDist, minI;


    while (treeSize < N) {
        minDist = maxDist;
        minI = -1;
        for (int i = 0; i < N; i++) {
            if (dist[i] < minDist && !intree[i]) {
                minDist = dist[i];
                minI = i;
            }
        }

        intree[minI] = 1;
        treeCost += minDist;
        treeSize++;

        for (int i = 0; i < N; i++) {
            if (graph[minI][i] < dist[i]) {
                dist[i] = graph[minI][i];
                source[i] = minI;
            }
        }
    }

    FILE* fout = fopen ("agrinet.out", "w");
    fprintf (fout, "%d\n", treeCost);
}

int main() {
    FILE* fin = fopen("agrinet.in", "r");
    fscanf (fin, "%d\n", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf (fin, "%d ", &graph[i][j]);
        }
    }
    search();
    return 0;
}
