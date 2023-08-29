/*
ID: cyrilsh1
TASK: humble
LANG: C++       
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int K, N;
long long nums[100001]; 

int binarySearch(int i, int val) {
    int left = 0;
    int right = i;
    int ans = -1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] > val) {
            right = mid - 1;
            ans = mid;
        }
        else left = mid + 1;
    }
    return ans;
}

int main() {
    FILE* fin = fopen ("humble.in", "r");
    fscanf (fin, "%d %d\n", &K, &N);
    int S[K];
    for (int i = 0; i < K; i++) {
        fscanf (fin, "%d ", &S[i]);
    }
    nums[0] = 1;
    int idx;
    long long minNum, val;
    for (int i = 1; i <= N; i++) {
        minNum = LLONG_MAX;
        for (int k = 0; k < K; k++) {
            val = (nums[i-1] / S[k]);
            idx = binarySearch(i, val);
            minNum = min(minNum, nums[idx] * S[k]);
            if (minNum == nums[i-1] + 1) break;
        }
        nums[i] = minNum;
    }
    FILE* fout = fopen ("humble.out", "w");
    fprintf (fout, "%lld\n", nums[N]);
    return 0;
}
