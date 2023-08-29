#include <bits/stdc++.h>

using namespace std;

int main() {
    int numTests; cin >> numTests;
    for (int i = 0; i < numTests; i++) {
        int n; cin >> n;
        char str[n+1];
        scanf("%s", str);
        int sum = 0;
        vector<int> maxes(n, 0);
        int best;
        for (int i = 0; i < n; i++) {
            if (str[i] == 'L') {
                sum += i;
                if (n-1-i > i) maxes[n-1-i] += 1;
            }
            if (str[i] == 'R') {
                sum += (n-1-i);
                if (i > n-1-i) maxes[i] += 1;
            }
        }

        int counter = 0;
        for (int i = n-1; i >= 0; i--) {
            while (maxes[i] != 0 && counter < n) {
                maxes[i]--;
                sum += max(maxes[i] - i, maxes[i] - (n-1-i));
                counter++;
                cout << sum << " ";
            }
        }
        if (counter < n-1) {
            while (counter < n-1) {
                cout << sum << " ";
                counter++;
            }
        }
        cout << "\n";
    }
}