#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
using vi = vector<int>;

int main() {
    fastio
    int n; cin >> n;

    vector<char> hand(n);
    for (int i = 0; i < n; i++) {
        cin >> hand[i];
    }

    auto card_val = [](char c) {
        switch (c) {
            case 'A': return 1;
            case 'T':
            case 'J':
            case 'Q':
            case 'K':
                return 10;
        }
        return (c - '0');
    };

     auto order = [](char c) {
        switch (c) {
            case 'A': return 1;
            case 'T': return 10;
            case 'J': return 11;
            case 'Q': return 12;
            case 'K': return 13;
        }
        return (c - '0');
    };

    sort(hand.begin(), hand.end(), [&](char a, char b) {
        return order(a) < order(b);
    });

    auto num15 = [&]() {
        vector<ll> dp(16);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int val = card_val(hand[i]);
            for (int j = 15; j >= val; j--) {
                dp[j] += dp[j - val];
            }
            /* for (int j = 0; j <= 15; j++)
                cerr<<dp[j]<<" ";
            cerr<<endl; */
        }
        return dp[15] * 2;
    };

    auto pairs = [&]() {
        vi count(14);
        for (int i = 0; i < n; i++) {
            count[order(hand[i])]++;
        }
        int ans = 0;
        for (int i = 1; i <= 13; i++) {
            ans += count[i] * (count[i] - 1) / 2;
        }
        return ans * 2;
    };

    auto runs = [&]() {
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            vi count(14);
            int length = 1;
            count[order(hand[i-1])]++;
            while ((hand[i] == hand[i-1] ||
                order(hand[i]) - 1 == order(hand[i-1]))
                && i < n) {
                count[order(hand[i])]++;
                if (hand[i] != hand[i-1]) {
                    length++;
                }
                i++;
            }
            if (length < 3) continue;
            ll combos = 1;
            for (int i = 1; i <= 13; i++) {
                if (count[i] == 0) continue;
                combos *= count[i];
            }
            ans += combos * length;
        }
        return ans;
    };
    /* dbg(num15())
    dbg(pairs())
    dbg(runs()) */
    ll ans = num15() + pairs() + runs();
    cout<<ans<<endl;
}