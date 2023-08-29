#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define maxVal 1000000000

char convertChar(char c) {
    if (c >= 'A') return (char) c - 'A' + 'a';
    return c;
}

bool isVowel(char c) {
    if (c >= 'A') c = (char) c - 'A' + 'a';
    if (c - 'a' == 0 | c - 'e' == 0 | c - 'i' == 0 | c - 'o' == 0 | c - 'u' == 0) return true;
    return false;
}

bool isY(char c) {
    if (c - 'y' == 0) return true;
    return false;
}

bool isNum(char c) {
    if (c - '1' < 10) return true;
    else return false;
}


int main() {
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        while (!) {
            string s;
            cin >> s;
            if (isVowel(c)) nvowels++;
            
            cin >> c;
        }
    }
}