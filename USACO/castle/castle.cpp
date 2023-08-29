/*
ID: cyrilsh1
TASK: castle
LANG: C++       
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define maxSize 50

int M, N;
vector<int> graph[maxSize*maxSize];

int numComponents,roomSize,largestRoom;
int rooms[maxSize*maxSize];
int comps[maxSize*maxSize];

void floodFill(int state) {
    for (int i = 0; i < graph[state].size(); i++) {
        if (comps[graph[state][i]] == 0) {
            comps[graph[state][i]] = numComponents;
            floodFill(graph[state][i]);
            roomSize += 1;
        }
    }
}

void findRooms() {
    numComponents = 0; largestRoom = -1;
    for (int i = 0; i < N*M; i++) {
        if (comps[i] == 0) {
            numComponents += 1;
            comps[i] = numComponents;
            roomSize = 1;
            floodFill(i);
            largestRoom = max(largestRoom, roomSize);
            rooms[numComponents-1] = roomSize;
        }
    }
}

int main() {
    FILE* fin = fopen ("castle.in", "r");
    FILE* fout = fopen ("castle.out", "w");
    fscanf (fin, "%d %d\n", &M, &N);
    int index;
    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            index = M*i + j;
            fscanf (fin, "%d ", &num);
            if (!(num & 0x8) && i < N-1)  {
                graph[index].push_back(index+M);
                graph[index+M].push_back(index);
            }
            if (!(num & 0x4) && j < M-1) {
                graph[index].push_back(index+1);
                graph[index+1].push_back(index);
            }
        }
    }
    findRooms();
    fprintf (fout, "%d\n", numComponents);
    fprintf (fout, "%d\n", largestRoom);

    pair<int,int> wallSquare;
    int largestRoomSize = -1;
    int currentRoomSize = -1;
    int edges[2];
    string dir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // only try edges that connect different regions.
            index = M*i + j;
            edges[0] = index - M; edges[1] = index + 1;
            for (int k = 0; k < 2; k++) {
                if (k == 0 && edges[0] < 0) continue;
                if (k == 1 && edges[1] % M == 0) continue;
                if (comps[index] == comps[edges[k]]) continue;
                currentRoomSize = rooms[comps[index]-1] + rooms[comps[edges[k]]-1];
                if (currentRoomSize >= largestRoomSize) {
                    if (currentRoomSize == largestRoomSize) {
                        if (j+1 > wallSquare.second) continue;
                        if (j+1 == wallSquare.second && i+1 <= wallSquare.first) continue;
                    }
                    wallSquare = make_pair(i+1, j+1);
                    dir = k == 0 ? "N" : "E";
                    largestRoomSize = currentRoomSize;
                }
            }
        }
    }   
    fprintf (fout, "%d\n", largestRoomSize);
    fprintf (fout, "%d %d %s\n", wallSquare.first, wallSquare.second, dir.c_str());
    return 0;
}
