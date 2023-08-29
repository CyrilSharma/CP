/*
ID: cyrilsh1
TASK: sort3
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

#define maxN 1000

int N;
int counters[4];
int list[maxN];
int sortedList[maxN];

int main() {
    FILE* fin = fopen("sort3.in", "r");
    FILE* fout = fopen("sort3.out", "w");

    fscanf (fin, "%d\n", &N);
    for (int i = 0; i < N; i++) {
        fscanf (fin, "%d\n", &list[i]);
        counters[list[i]] += 1;
    }

    int k = 1;
    int num = 0;
    for (int i = 0; i < N; i++) {
        sortedList[i] = k;
        if (num < counters[k]-1) num += 1;
        else {
            k += 1;
            num = 0;
        }
    }

    int temp;
    int swaps = 0;
    int swapIndex;
    for (int i = 0; i < N; i++) {
        if (list[i] != sortedList[i]) {
            for (int j = i+1; j < N; j++) {
                if (list[j] == sortedList[i] && list[i] == sortedList[j]) {
                    swapIndex = j;
                    break;
                }
                if (list[j] == sortedList[i] && list[j] != sortedList[j]) swapIndex = j;
            }
            temp = list[swapIndex];
            list[swapIndex] = list[i];
            list[i] = temp;
            swaps += 1;
        }
    }
    fprintf (fout, "%d\n", swaps);
    return 0;
}
