/*
ID: cyrilsh1
TASK: contact
LANG: C++       
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, string> counts[8192];
int nums[13];

bool pairSort (pair<int, string> a, pair<int, string> b) { 
    if (a.first > b.first) return true;
    else if (a.first == b.first) {
        if (a.second.size() < b.second.size()) return true;
        else if (a.second.size() == b.second.size())
            if (a.second < b.second) return true;
    }
    return false;
}

int main() {
    int A, B, N;
    FILE* fin = fopen ("contact.in", "r");
    fscanf (fin, "%d %d %d\n", &A, &B, &N);

    char c;
    int b, max;
    string s = "";
    string n;
    while (fscanf(fin, "%c", &c) != EOF) {
        if (c == '\n') continue;
        s += c;
        if (s.size() == 13) s = s.substr(1, s.size());
        b = (int) (c - '0');
        for (int i = A; i <= B; i++) {
            max = pow(2, i) - 1;
            nums[i] = (nums[i] << 1) + b;
            nums[i] &= max;
            if (s.size() < i) continue; 
            n = s.substr(s.size() - i, s.size());
            // there are smarter ways to encode different length sequences as unique...
            counts[nums[i] + (int) pow(2,i)].first += 1;
            counts[nums[i] + (int) pow(2,i)].second = n;
        }
    }

    vector<pair<int, string> > seq;
    for (int i = 0; i < pow(2, B+1); i++) {
        if (counts[i].first >= 1) {
            seq.push_back(counts[i]);
        }
    }
    sort(seq.begin(), seq.end(), pairSort);
    FILE* fout = fopen ("contact.out", "w");

    int prev = -1;
    int i = 0;
    int num_freq = 0;
    int num_in_line = 0;
    // this can be wayyyyyy simpler
    while (num_freq <= N && i < seq.size()) {
        if (seq[i].first != prev) {
            num_freq += 1;
            num_in_line = 0;
            if (num_freq == N+1) break;
            if (i != 0) fprintf (fout, "%c", '\n');
            fprintf (fout, "%d\n", seq[i].first);
            fprintf (fout, "%s", seq[i].second.c_str());
            num_in_line++;
        }
        else {
            if (num_in_line == 6) {
                fprintf (fout, "%c", '\n');
                fprintf (fout, "%s", seq[i].second.c_str());
                num_in_line = 0;
            }
            else {
                fprintf (fout, " %s", seq[i].second.c_str());
            }
            num_in_line++;
        }
        prev = seq[i].first;
        i++;
    }
    fprintf (fout, "%c", '\n');
    return 0;
}
