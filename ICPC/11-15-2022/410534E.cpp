#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> days(n);
    int totaldays = 0;
    for (int i = 0; i < n; i++) {
        cin >> days[i];
        totaldays += days[i];
    }

    queue<int> nums;
    int best=0; int total=0;
    int mctr=0; int dctr=0;
    for (int i = 0; i < x + totaldays; i++) {
        if (dctr >= days[mctr]) {
            dctr = 0;
            mctr = (mctr + 1) % n;
        }
        //cout<<dctr+1<<"\n";
        nums.push(dctr+1);
        total += (dctr+1);
        if (nums.size() > x) {
            int rem = nums.front(); nums.pop();
            total -= rem;
        }
        best=max(total,best);
        dctr++;
    }
    cout<<best<<"\n";
}