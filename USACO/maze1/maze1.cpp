/*
ID: cyrilsh1
TASK: maze1
LANG: C++       
*/
#include <iostream>
using namespace std;

#define maxH 100
#define maxW 38
#define maxInt 2147483647

int W, H;

char maze[2*maxH+1][2*maxW+1];
int dist[maxH][maxW];
int visited[maxH][maxW];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void djikstras(int sx, int sy) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dist[i][j] = maxInt;
            visited[i][j] = 0;
        }
    }
    dist[sx][sy] = 0;

    int minDist;
    int cx, cy;
    for (int n = 0; n < W*H; n++) {
        minDist = maxInt;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (visited[i][j]) continue;
                if (dist[i][j] < minDist) {
                    minDist = dist[i][j];
                    cx = i; cy = j;
                }
            }
        }

        visited[cx][cy] = 1;
        for (int i = 0; i <= 4; i++) {
            if (cx + dx[i] < 0  || cx + dx[i] >= H || cy + dy[i] < 0 || cy + dy[i] >= W) continue;
            if (!visited[cx + dx[i]][cy + dy[i]]) {
                if (maze[(2*cx + 1) + dx[i]][(2*cy + 1) + dy[i]] != ' ') continue;
                if (dist[cx][cy] + 1 < dist[cx + dx[i]][cy + dy[i]]) {
                    dist[cx + dx[i]][cy + dy[i]] = dist[cx][cy] + 1;
                }
            }
        }
    }
}

int main() {
    FILE* fin = fopen("maze1.in", "r");
    FILE* fout = fopen("maze1.out", "w");
    fscanf (fin, "%d %d\n", &W, &H);

    pair<int,int> exits[2];
    int numExits = 0;
    char c;
    for (int i = 0; i < 2*H + 1; i++) {
        for (int j = 0; j < 2*W + 2; j++) {
            fscanf(fin, "%c", &c);
            if (j == 2*W + 1) continue;
            maze[i][j] = c;
            if(maze[i][j] == ' ' && (i == 2*H || j == 2*W || i == 0 || j == 0)) {
                exits[numExits] = make_pair((i-1)/2, (j-1)/2);
                numExits++;
            }
        }
    }

    int furthest = -1;
    int totals[H][W];
    djikstras(exits[0].first, exits[0].second);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            totals[i][j] = dist[i][j];
        }
    }
    djikstras(exits[1].first, exits[1].second);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            totals[i][j] = min(totals[i][j], dist[i][j]);
            furthest = max(totals[i][j], furthest);
        }
    }
    // take one more step to exit the maze.
    fprintf (fout, "%d\n", furthest+1);
    return 0;
}
