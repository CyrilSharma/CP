/*
ID: cyrilsh1
TASK: dualpal
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

string convertBase(int num, int base) {
    int division = num;
    int numDigits = 0;
    while (division != 0) {
        division = division / base;
        numDigits += 1;
    }

    string convertedBase = "";
    int remainder = num;
    int k;
    for (int i = numDigits - 1; i >= 0; i--) {
        k = remainder / pow(base, i);
        remainder = remainder - k * pow(base, i);
        convertedBase += to_string(k);
    }
    return convertedBase;
}

bool isPalindrome(string s) {
    string h1 = s.substr(0, floor((double)s.length()/2.));
    string h2 = s.substr(ceil((double)s.length()/2.), s.length()-1);
    for (int i = 0; i < h1.length(); i++) {
        if (h1[i] != h2[h1.length() - 1 - i])
            return false;
    }
    return true;
}

int main() {
    int n, s;
    FILE* fin = fopen("dualpal.in", "r");
    fscanf (fin, "%d %d\n", &n, &s);

    FILE* fout = fopen("dualpal.out", "w");

    int numFound = 0;
    int palindromeBases = 0;
    int i = s+1;
    while (numFound != n) {
        palindromeBases = 0;
        for (int b = 2; b <= 10; b++) {
            if (isPalindrome(convertBase(i, b)))
                palindromeBases += 1;
            if (palindromeBases == 2) {
                fprintf (fout, "%d\n", i);
                numFound += 1;
                break;
            }
        }
        i++;
    }
    return 0;
}
