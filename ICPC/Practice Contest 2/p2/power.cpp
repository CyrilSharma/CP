#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define maxVal 1000000000

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
        // difference of integers must equal an integer to the fourth.
        // a is limited between 1 and 16.
        // there would not be a unique solution if the first corner was undetermined.
        // thus, you can determine what the first corner i
    }

    // 1, 16, 81, 256, 625, 1296, 3.14 * 10 ~ 32 is max quartic difference.
    // quartic difference must be difference of integers..
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

        }
    }

}