/*
ID: cyrilsh1
TASK: fact4
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

int main() {
    int N;
    FILE* fin = fopen ("fact4.in", "r");
    fscanf (fin, "%d\n", &N);
    int temp;
    int num2s = 0;
    int num5s = 0;
    int fact = 1;
    for (int i = 1; i <= N; i++) {
        temp = i;
        while (temp % 2 == 0) {
            temp /= 2;
            num2s++;
        }
        while (temp % 5 == 0) {
            temp /= 5;
            num5s++;
        }
        fact *= temp;
        fact = fact % 10;
    }
    int num;
    if (num2s - num5s <= 4) num = num2s - num5s;
    else num = ((num2s - num5s - 1) % 4) + 1;
    for (int i = 0; i < num; i++) {
        fact *= 2;
        fact = fact % 10;
    }
    FILE* fout = fopen ("fact4.out", "w");
    fprintf (fout, "%d\n", fact);
    return 0;
}
