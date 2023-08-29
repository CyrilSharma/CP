#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int numTests; cin >> numTests;
    for (int i = 0; i < numTests; i++) {
        int a, b;
        cin >> a; cin >> b;
        cout << a + b << "\n";
    }
}