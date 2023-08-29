/*
ID: cyrilsh1
TASK: crypt1
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

bool validNumber(int v, string validNums, int desiredLen) {
    string num = to_string(v);
    if (num.length() != desiredLen)
        return false;

    bool inSet;
    for (int i = 0; i < num.length(); i++) {
        inSet = false;
        for (int j = 0; j < validNums.length(); j++) {
            if (validNums[j] == num[i])
                inSet = true;
        }
        if (!inSet)
            return false;   
    }
    return true;
}

int computeCombos(string validNums, string nums, int counter) {
    if (counter == 5) {
        int num1 = stoi(nums.substr(0, 3));
        string d1 = string(1, nums[3]);
        string d2 = string(1, nums[4]);
        if (!validNumber(num1 * stoi(d1), validNums, 3)) {
            // std::cout << "hi1\n";
            return 0;
        }
        if (!validNumber(num1 * stoi(d2), validNums, 3)) {
            // std::cout << "hi2\n";
            return 0;
        }
        if (!validNumber(num1 * stoi(nums.substr(3,5)), validNums, 4)) {
            // std::cout << "hi3\n";
            return 0;
        }
        return 1;
    }

    int combos = 0;
    for (int i = 0; i < validNums.length(); i++)
        combos += computeCombos(validNums, nums + validNums[i], counter+1);
    return combos;
}


int main() {
    FILE *fin, *fout;
    fin = fopen("crypt1.in", "r");
    fout = fopen("crypt1.out", "w");

    int n;
    fscanf (fin, "%d\n", &n);

    string validNums = "";
    int num;
    for (int i = 0; i < n-1; i++) {
        fscanf (fin, "%d ", &num);
        validNums += to_string(num);
    }
    fscanf (fin, "%d\n", &num);
    validNums += to_string(num);
    // std::cout << validNumber(128, validNums, 3) << "\n";
    int result = computeCombos(validNums, "", 0);
    std::cout << result << "\n";
    fprintf (fout, "%d\n", result);
    return 0;
}
