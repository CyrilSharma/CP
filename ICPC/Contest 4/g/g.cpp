#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int minsize = min(a.size(), b.size());
    for (int i = 0; i < minsize; i++) {
        if ((int)(a[i] - '0') < (int)(b[i] - '0')) {
            cout << a << "<" << b << "\n";
            return 0;
        }
        else if ((int)(a[i] - '0') > (int)(b[i] - '0')) {
            cout << a << ">" << b << "\n";
            return 0;
        }
    }
    if (a.size() == b.size()) {
        cout << a << "=" << b << "\n";
        return 0;
    }
    else {
        if (a.size() > b.size())
            cout << a << ">" << b << "\n";
        else 
            cout << a << "<" << b << "\n";
    }       
}