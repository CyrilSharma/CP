#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    if (n >= 2) {
        int max = nums[nums.size()-1];
        int diff = nums[1]-nums[0];
        if (nums[0]+diff <= max-diff)
            cout << nums[1];
        else 
            cout << (double)nums[0]+ (double)(max-nums[0])/2;
    }
    else cout << nums[0];
}