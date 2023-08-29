/*
ID: cyrilsh1
TASK: wormhole
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define MAX_DIST 2147483647

struct coord {
    int x;
    int y;
};

bool checkArrangement(coord *coords, int *arr, int n) {
    // unnecessary just update the position...
    int curI;
    int minDist;
    int minI;
    // unnecessary, just checked if you escaped or not.
    int visited[12];

    bool escaped;
    coord pos;

    for (int i = 0; i < n; i++) {
        // unnecessary if you used globals.
        for (int j = 0; j < n; j++)
            visited[j] = 0;
        curI = i;
        pos = coords[i];
        escaped = false;

        // never hits the same location twice.
        // or you can just use a for loop, the length of the loop can't be longer then N.
        while (visited[curI] != 2) {
            // instead of all this, why not update position by teleporting it and then choosing the adjacent element.
            // if position reaches an invalid state no loop, but otherwise there is a loop.
            // this way you don't end up having 10000000 if statements and local variables, in fact you only end up updating one variable!
            minI = curI;
            minDist = MAX_DIST;
            escaped = true;
            for (int j = 0; j < n; j++) {
                if (coords[j].y == pos.y) {
                    if ((coords[j].x - pos.x) > 0) {
                        // closer portal.
                        if (coords[j].x - pos.x < minDist) {
                            minDist = coords[j].x - pos.x;
                            minI = j;
                            escaped = false;
                        }
                    }
                }
            }

            // no portal to run into.
            if (escaped) break;

            // only count a portal as visited when it's been teleported through.
            curI = arr[minI];
            visited[curI] += 1;
            pos = coords[curI];
        }

        if (!escaped)
            return true;
    }

    return false;
}

int calc(coord *coords, int n, int *arrangement, int *chosen, int counter) {
    // fairly clean but you can avoid using a counter altogether if you just check to see if everything is paired. less error prone too.
    if (n/2 == counter) {
        if (checkArrangement(coords, arrangement, n)) return 1;
        return 0;
    }

    // THE REAL issue here is the chosen and arrangement arrays are redundant...
    //  you should just load in a dummy value or smnth in the arrangement array for unpaired objects.

    // first number that has not already been chosen
    // also you can just do int i; and then for (i = 0;) that way you can just use the value of i outside the loop.
    int p1;
    for (int i = 0; i < n; i++) {
        if (chosen[i] != 1) {
            // this statement too
            p1 = i;
            // this statement too.
            chosen[i] = 1;
            break;
        }
    }
    
    // for each number that remains, make a new iteration
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (chosen[i] != 1) {
            // assembles a pair.
            arrangement[p1] = i;
            arrangement[i] = p1;
            // this could be eliminated
            chosen[i] = 1;

            total += calc(coords, n, arrangement, chosen, counter+1);

            // disassembles the pair
            // this statement as well
            chosen[i] = 0;

            arrangement[p1] = 0; arrangement[i] = 0;
        }
    }
    chosen[p1] = 0;
    return total;
}

int main() {
    FILE* fin = fopen("wormhole.in", "r");
    FILE* fout = fopen("wormhole.out", "w");

    int n;
    fscanf (fin, "%d\n", &n);
    coord coords[n];
    for (int i = 0; i < n; i++) {
        fscanf (fin, "%d %d\n", &coords[i].x, &coords[i].y);
    }
    /* 
    for (int i = 0; i < n; i++) {
        std::cout << "(" << coords[i].x << " " << coords[i].y << ")\n";
    }
    */
    /* int arrangement[6] = {2, 5, 0, 4, 3, 1};
    std::cout << checkArrangement(coords, arrangement, n) << "\n"; */

    int arrangement[n];
    int chosen[n];

    for (int i = 0; i < n; i++) {
        arrangement[i] = 0;
        chosen[i] = 0;
    }

    int result = calc(coords, n, arrangement, chosen, 0);
    fprintf (fout, "%d\n", result);
    return 0;
}
