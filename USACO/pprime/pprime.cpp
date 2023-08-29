/*
ID: cyrilsh1
TASK: pprime
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

int A, B;
string maxVal;
vector<int> pprimes;

string reverseS(string s) {
    string newS = s;
    for (int i = s.size()-1; i>=0; i--) {
        newS[s.size()-1-i] = s[i];
    }
    return newS;
}

bool isValid(string num) {
    int n = stoi(num);
    if (n > B || n < A) return false;
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void checkPalindromePrimes(string num) {
    int startDigits[5] = {1,3,5,7,9};
    // checks 1 and 2 digit numbers.
    if (num.size() == 0) {
        for (int i = 0; i < 5; i++) {
            num = to_string(startDigits[i]);
            if (isValid(num)) pprimes.push_back(stoi(num));
            if (isValid(num + reverseS(num))) pprimes.push_back(stoi(num + reverseS(num))); 
            if (i!=5) checkPalindromePrimes(num);
        }
        return;
    }

    if (num.size() > maxVal.size()/2) return;

    string input;
    for (int i = 0; i < 10; i++) {
        input = num + to_string(i) + reverseS(num);
        if (isValid(input)) pprimes.push_back(stoi(input));

        num += to_string(i);

        input = num + reverseS(num);
        if (input.size() <= maxVal.size()) {
            if (isValid(input)) pprimes.push_back(stoi(input));
            checkPalindromePrimes(num);
        }

        num.pop_back();
    }
}


int main() {
    FILE* fin = fopen("pprime.in", "r");
    FILE* fout = fopen("pprime.out", "w");

    fscanf (fin, "%d %d\n", &A, &B);
    maxVal = to_string(B);

    string num = "";
    checkPalindromePrimes(num);

    sort(pprimes.begin(), pprimes.end());
    for (int i = 0; i < pprimes.size(); i++) {
        fprintf (fout, "%d\n", pprimes[i]);
    }
    return 0;
}
