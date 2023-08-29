/*
ID: cyrilsh1
TASK: namenum
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#define MaxNameLength 15
#define MaxNumDigits 12
#define dictSize 5000

char digitToChar(int digit, int specifier) {
    if (digit < 7) {
        return static_cast<char>(3 * (digit - 2) + 'A' + specifier);
    }
    else {
        if (digit == 7) {
            if (specifier == 0) 
                return 'P';
            else if (specifier == 1)
                return 'R';
            else
                return 'S';
        }
        else if (digit == 8) {
            if (specifier == 0) 
                return 'T';
            else if (specifier == 1)
                return 'U';
            else
                return 'V';
        }
        else {
            if (specifier == 0) 
                return 'W';
            else if (specifier == 1)
                return 'X';
            else
                return 'Y';
        }
    }
}

bool validWord(string word, vector<int> digits) {
    bool oneMatching;
    for (int i = 0; i < digits.size(); i++) {
        oneMatching = false;
        for (int j = 0; j < 3; j++) {
            if (word[i] == digitToChar(digits[i], j)) {
                oneMatching = true;
            }
        }
        if (!oneMatching)
            return false;
    }
    return true;
}

int main() {
    string dict[MaxNameLength][dictSize];

    FILE* fdict = fopen("dict.txt", "r");
    char buff[MaxNameLength];
    string word;
    int counters[MaxNameLength];
    while (fscanf (fdict, "%s\n", buff) != EOF) {
        word = string(buff);
        dict[word.length()][counters[word.length()]] = word;
        counters[word.length()] += 1;
    }
    
    long long serial;
    FILE* fin = fopen("namenum.in", "r");
    fscanf (fin, "%lld\n", &serial);
    std::cout << serial << "\n";


    int numDigits = 0;
    vector<int> digits;
    int digit;
    long long division;
    long long remainder = 0;
    for (int i = MaxNumDigits-1; i >= 0; i--) {
        division = serial / pow(10, i);
        digit = division - remainder * 10;
        if (digit != 0 && numDigits == 0)
            numDigits = i+1;
        if (numDigits != 0) {
            digits.push_back(digit);
        }
        remainder = division;
    }

    vector<string> validNames;
    for (int i = 0; i < counters[numDigits]; i++) {
        if (validWord(dict[numDigits][i], digits))
            validNames.push_back(dict[numDigits][i]);
    }

    for (int i = 0; i < digits.size(); i++) {
        std::cout << digits[i] << "\n";
    }
    
    sort(validNames.begin(), validNames.end());
    FILE* fout = fopen("namenum.out", "w");

    
    if (validNames.size() == 0)
        fprintf (fout, "%s\n", "NONE");
    else {
        for (int i = 0; i < validNames.size(); i++) {
            fprintf (fout, "%s\n", validNames[i].c_str());
        }
    }
}
