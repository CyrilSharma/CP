/*
ID: cyrilsh1
TASK: milk3
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

int bucket_caps[3];
int buckets[3];
int visited[21][21][21];
int milkAmounts[21];
int numAmounts = 0;

void search() {
    // if the first bucket is empty, markdown how much milk is in bucket c.
    if (buckets[0] == 0) {
        if (milkAmounts[buckets[2]] != 1) {
            milkAmounts[buckets[2]] = 1;
            numAmounts += 1;
        }
    } 

    int b1_amount;
    int b2_amount;
    for (int b1 = 0; b1 < 3; b1++) {
        b1_amount = buckets[b1];
        // bucket empty
        if (buckets[b1] == 0) continue;

        for (int b2 = 0; b2 < 3; b2++) {
            b2_amount = buckets[b2];
            if (b1 == b2) continue;
            // can't pour into a full bucket.
            if (buckets[b2] == bucket_caps[b2]) continue;

            if (buckets[b1] + buckets[b2] <= bucket_caps[b2]) {
                buckets[b2] = buckets[b1] + buckets[b2]; buckets[b1] = 0;
                if (visited[buckets[0]][buckets[1]][buckets[2]] != 1) {
                    visited[buckets[0]][buckets[1]][buckets[2]] = 1;
                    search();
                }
                buckets[b1] = b1_amount; buckets[b2] = b2_amount;
            }
            else {
                buckets[b1] -= (bucket_caps[b2] - buckets[b2]); buckets[b2] = bucket_caps[b2];
                if (visited[buckets[0]][buckets[1]][buckets[2]] != 1) {
                    visited[buckets[0]][buckets[1]][buckets[2]] = 1;
                    search();
                }
                buckets[b1] = b1_amount; buckets[b2] = b2_amount;
            }

        }
    }
}

int main() {
    FILE* fin = fopen("milk3.in", "r");
    FILE* fout = fopen("milk3.out", "w");

    fscanf (fin, "%d %d %d\n", &bucket_caps[0], &bucket_caps[1], &bucket_caps[2]);
    buckets[0] = buckets[1] = 0; buckets[2] = bucket_caps[2];
    search();

    int numCounted = 0;
    std::cout << numAmounts << "\n";
    for (int i = 0; i < 21; i++) {
        if (milkAmounts[i] == 1) {
            if (numCounted < numAmounts-1) {
                std::cout << numCounted << "\n";
                fprintf (fout, "%d ", i);
                numCounted += 1;
            }
            else {
                std::cout << numCounted << "\n";
                fprintf (fout, "%d\n", i);
            }
        }
    }
    return 0;
}
