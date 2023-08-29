/*
ID: cyrilsh1
TASK: milk
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct farmer {
    int price;
    int amount;
};

int compare (const void * a, const void * b) {

  farmer *farmerA = (farmer *)a;
  farmer *farmerB = (farmer *)b;

  return ( farmerA->price - farmerB->price );
}

int main() {
    int n, m;
    FILE* fin = fopen("milk.in", "r");
    fscanf (fin, "%d %d\n", &n, &m);

    farmer farmers[m];
    for (int i = 0; i < m; i++) {
        fscanf (fin, "%d %d\n", &farmers[i].price, &farmers[i].amount);
    }

    qsort (farmers, m, sizeof(farmer), compare);

    int milkBought = 0;
    int payment = 0;
    int i = 0;
    while (milkBought < n) {
        if (farmers[i].amount < (n - milkBought)) {
            payment += farmers[i].amount * farmers[i].price;
            milkBought += farmers[i].amount;
        }
        else {
            payment += farmers[i].price * (n - milkBought);
            milkBought = n;
        }
        i++;
    }

    FILE* fout = fopen("milk.out", "w");
    fprintf (fout, "%d\n", payment);
    return 0;
}
