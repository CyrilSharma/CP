/*
ID: cyrilsh1
TASK: ttwo
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

struct node {
    int x, y, dir;
    bool operator==(const node &rhs) {
        if (this->x == rhs.x && this->y == rhs.y && this->dir == rhs.dir) return true;
        return false;
    }
};

node farmer;
node cow;
int walls[10][10];

void simulate(node &pos) {
    int incX, incY, newX, newY, newDir, cycleStart;
    bool blocked;
    switch (pos.dir) {
        case 0:
            incX = 0; incY = -1; break;
        case 1:
            incX = 1; incY = 0; break;
        case 2:
            incX = 0; incY = 1; break;
        case 3: 
            incX = -1; incY = 0; break;
    }
    newX = pos.x + incX;
    newY = pos.y + incY;
    blocked = false;
    if ((newX < 0 || newX > 9) || (newY < 0 || newY > 9)) blocked = true;
    else if (walls[newX][newY]) blocked = true;

    if (blocked) {
        newDir = (pos.dir + 1) % 4;
        newX = pos.x; newY = pos.y;
    }
    else newDir = pos.dir;
    pos.x = newX; pos.y = newY; pos.dir = newDir;
}

int main() {
    FILE* fin = fopen("ttwo.in", "r");
    FILE* fout = fopen("ttwo.out", "w");
    char c;
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            node n = {x, y, 0};
            fscanf (fin, "%c ", &c);
            if (c == 'F') farmer = n;
            else if (c == 'C') cow = n;
            else if (c == '*') walls[x][y] = 1;
        }
    }
    for (int i = 0; i < 10000; i++) {
        simulate(farmer);
        simulate(cow);
        if (farmer.x == cow.x && farmer.y == cow.y) {
            fprintf (fout, "%d\n", i+1);
            exit(0);
        }
    }
    fprintf (fout, "%d\n", 0);
    return 0;
}
