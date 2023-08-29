/*
ID: cyrilsh1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

std::vector<string> split(string s) {
    string substr = s;
    string token;
    std::vector<string> tokens;
    bool stringFinished = false;
    size_t tokenIndex;
    while (!stringFinished) {
        tokenIndex = substr.find(" ");
        token = substr.substr(0, tokenIndex);
        tokens.push_back(token);
        if (tokenIndex != std::string::npos) {
            substr = substr.substr(tokenIndex + 1, std::string::npos);
        }
        else {
            stringFinished = true;
        }
    }
    return tokens;
}

int main() {
    std::ifstream fin("gift1.in");
    std::ofstream fout("gift1.out");

    int numPeople;
    string buff;
    getline(fin, buff);
    numPeople = stoi(buff);

    // for keeping track of order.
    string people[numPeople];
    map<string, int> balance;
    
    string key;
    for (int i = 0; i < numPeople; i++) {
        getline(fin, key);
        people[i] = key;
        balance[key] = 0;
    }
    
    string account;
    string values;
    vector<string> tokens;
    int amount, numRec, splitAmount, remainder;
    string person;

    for (int i = 0; i < numPeople; i++) {
        getline(fin, account);
        getline(fin, values);
        tokens = split(values);
        std::cout << values << "\n";
        amount = stoi(tokens[0]);
        numRec = stoi(tokens[1]);
        splitAmount = numRec != 0 ? amount / numRec : 0;
        remainder = amount - numRec * splitAmount;
        if (numRec > 0) {
            balance[account] -= amount;
            balance[account] += remainder;
        } 
        else {
            balance[account] += amount;
        }
        for (int i = 0; i < numRec; i++) {
            getline(fin, person);
            balance[person] += splitAmount;
        }
    }

    for (int i = 0; i < numPeople; i++) {
        fout << people[i] << " " << balance[people[i]] << "\n";
    }
}