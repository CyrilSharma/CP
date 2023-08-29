/*
ID: cyrilsh1
TASK: palsquare
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
    int numDigits = 0;
    int division = num;
    while (division != 0) {
        division = division / base;
        numDigits += 1;
    }


    string convertedNum = "";
    int remainder = num;
    int k;
    bool numberStarted = false;
    for (int i = numDigits-1; i >= 0; i--) {
        k = remainder / pow(base, i);
        remainder = remainder - k * pow(base, i);
        if (k != 0)
            numberStarted = true;
        if (numberStarted) {
            if (k < 10)
                convertedNum += "" + to_string(k);
            else
                convertedNum += static_cast<char>('A' + k - 10);
        }
    }
    return convertedNum;
}

bool isPalindrome(string num) {
    string s = num;
    string h1 = s.substr(0, floor((double)(s.length()) / 2.));
    string h2 = s.substr(ceil((double)(s.length()) / 2.), s.length() - 1);
    for (int i = 0; i < h1.length(); i++) {
        if (h1[i] != h2[h1.length() - 1 - i])
            return false;
    }
    return true;
}

int main() {
    int base;
    FILE* fin = fopen("palsquare.in", "r");
    fscanf (fin, "%d\n", &base);
    FILE* fout = fopen("palsquare.out", "w");

    string convertedSquare;
    for (int n = 1; n < 300; n++) {
        convertedSquare = convertBase(n * n, base);
        if (isPalindrome(convertedSquare))
            fprintf (fout, "%s %s\n", convertBase(n, base).c_str(), convertedSquare.c_str());
    }
}
