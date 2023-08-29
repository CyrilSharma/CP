#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> digits(1010, 0);
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    int num=k; int i=0;
    vector<int> kdigits(1010, 0);
    while (num != 0) {
        kdigits[i] = num%4;
        num /= 4;
        i++;
    }
    
    int carry = 0;
    for (int i = 0; i < 1010; i++) {
        int sum = kdigits[i] + digits[i] + carry;
        if (sum > 3) carry = 1;
        else carry = 0;
        digits[i] = sum%4;
    }

    int finalind = 1009;
    while (digits[finalind] == 0) {
        finalind--;
    }

    for (int i = 0; i <= finalind; i++) {
        cout << digits[i] << " ";
    }
}