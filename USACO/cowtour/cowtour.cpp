/*
ID: cyrilsh1
TASK: cowtour
LANG: C++       
*/
#include <iostream>
#include <cmath>
using namespace std;

#define maxPastures 150
#define maxDouble 1e20

struct Pasture {
    int x;
    int y;
};

int N;
Pasture pastures[maxPastures];
int graph[maxPastures][maxPastures];
double dist[maxPastures][maxPastures];
int field[maxPastures];
int fieldSizes[maxPastures];
int numFields = 0;

double distance(Pasture a, Pasture b) {
    double distance = 0;
    distance += pow((double) (a.x - b.x), 2.0);
    distance += pow((double) (a.y - b.y), 2.0);
    distance = sqrt(distance);
    return distance;
}

void process(int pasture) {
    // iterate through neighbors
    fieldSizes[numFields-1] += 1;
    field[pasture] = numFields;
    for (int i = 0; i < N; i++) {
        if (graph[pasture][i] && field[i] == 0) process(i);
    }
}

void floodfill() {
    for (int i = 0; i < N; i++) {
        if (field[i] != 0) continue;
        numFields++;
        process(i);
    }
}

void calc() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (graph[i][j]) {
                // dist[i][j] = 1;
                dist[i][j] = distance(pastures[i], pastures[j]);
            }
            else dist[i][j] = maxDouble;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    double maxDists[N];
    for (int i = 0; i < N; i++) {
        maxDists[i] = -1.0;
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == maxDouble) continue;
            maxDists[i] = max(maxDists[i], dist[i][j]);
        }
    }

    double minDist = maxDouble;
    // minimum distance along paths between fields.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (field[i] == field[j]) continue;
            minDist = min(minDist, maxDists[i] + maxDists[j] + distance(pastures[i], pastures[j]));
        }
    }  
    // minimum distance for the overall thing.
    for (int i = 0; i < N; i++) {
        minDist = max(maxDists[i], minDist);
    } 

    FILE* fout = fopen("cowtour.out", "w");
    fprintf (fout, "%.6f\n", minDist);
}

int main() {
    FILE* fin = fopen("cowtour.in", "r");
    fscanf (fin, "%d\n", &N);
    for (int i = 0; i < N; i++) {
        fscanf (fin, "%d %d\n", &pastures[i].x, &pastures[i].y);
    }
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf (fin, "%c ", &c);
            graph[i][j] = (int) (c - '0');
        }
    }
    floodfill();
    calc();
    return 0;
}
