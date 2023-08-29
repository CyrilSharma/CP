/*
ID: cyrilsh1
TASK: comehome
LANG: C++       
*/
#include <iostream>
#include <cmath>
using namespace std;

#define maxDist 1e9

int P;
int graph[52][52];
int dist[52][52];

int main() {
    FILE* fin = fopen("comehome.in", "r");
    FILE* fout = fopen("comehome.out", "w");
    fscanf (fin, "%d\n", &P);
    char c1, c2;
    int a1;
    int p1, p2;
    for (int i = 0; i < P; i++) {
        fscanf(fin, "%c %c %d\n", &c1, &c2, &a1);
        if (c1 >= 'a') p1 = 26 + (int) (c1 - 'a');
        else p1 = (int) (c1 - 'A');
        if (c2 >= 'a') p2 = 26 + (int) (c2 - 'a');
        else p2 = (int) (c2 - 'A');
        if (graph[p1][p2] == 0) {
            graph[p1][p2] = a1;
            graph[p2][p1] = a1;
        }
        else {
            graph[p1][p2] = min(a1, graph[p1][p2]);
            graph[p2][p1] = min(a1, graph[p1][p2]);
        }
    }

    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == j) continue;
            if (graph[i][j] != 0) dist[i][j] = graph[i][j];
            else dist[i][j] = maxDist;
        }
    }

    for (int k = 0; k < 52; k++) {
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    int minDist = maxDist;
    char winner;
    for (int i = 0; i < 25; i++) {
        if (dist[i][25] < minDist) {
            minDist = dist[i][25];
            winner = (char)('A' + i);
        }
    }

    fprintf (fout, "%c %d\n", winner, minDist);
    return 0;
}
