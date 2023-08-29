#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int numTests; cin >> numTests;
    for (int i = 0; i < numTests; i++) {
        int n; cin >> n;
        char str1[n+1];
        scanf("%s", str1);
        char str2[n+1];
        scanf("%s", str2);
        bool equal = true;
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[i]) {
                if (!((str1[i] == 'G' || str1[i] == 'B') && (str2[i] == 'G' || str2[i] == 'B'))) {
                    cout << "NO\n";
                    equal = false;
                    break;
                }
            }
        }
        if (equal) cout << "YES\n";
    }
}