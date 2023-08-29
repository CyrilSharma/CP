#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define maxVal 1000000000

int main() {
    int tests;
    cin >> tests;

    vector<int> nums;
    int total = 0;
    for (int i = 0; i < 1e6; i++) {
        if (total > 1e6) break;
        total += i;
        nums.push_back(total);
    }

    int ind = 1;
    vector<int> tri(1e6+1);
    for (int i = 1; i < 1e6; i++) {
        if (i < nums[ind]) {
            tri[i] = ind-1;
        }
        else if (i == nums[ind]) {
            tri[i] = ind;
            ind++;
        }
    }

    for (int t = 0; t < tests; t++) {
        int n;
        cin >> n;
        cout << tri[n] << "\n";
    }
}