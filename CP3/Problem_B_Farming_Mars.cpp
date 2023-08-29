#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;

    vector<int> array(N);
    for (int i = 0; i < N; i++) {
        double num; cin >> num;
        array[i] = floor(num * 1000000);
    }

    struct query { int l, r, i; };
    vector<query> queries(M);
    for (int i = 0; i < M; i++) {
        int L, R; cin >> L >> R;
        queries[i] = {L-1, R-1, i};
    }

    const int W = 100;
    sort(queries.begin(), queries.end(),
        [&](query a, query b) {
            return make_pair(a.l / W, a.r) <
                make_pair(b.l / W, b.r);
        }
    );

    vector<int> mp(14000000 + 1);
    set<pair<int,int>> st;
    auto add = [&](int idx) {
        auto a = array[idx];
        if (mp[a]) {
            st.erase({mp[a], a});
            mp[a]++;
            st.insert({mp[a], a});
        } else {
            mp[a] = 1;
            st.insert({mp[a], a});
        }
    };

    auto remove = [&](int idx) {
        auto a = array[idx];
        assert(mp[a]);
        st.erase({mp[a], a});
        mp[a]--;
        st.insert({mp[a], a});
    };

    auto move = [&](int l1, int r1, int l2, int r2) {
        int s = min(r1, r2), e = max(r1, r2);
        for (int i = s + 1; i <= e; i++) {
            if (r1 > r2)    remove(i);
            else            add(i);
        }
        s = min(l1, l2), e = max(l1, l2);
        for (int i = s; i < e; i++) {
            if (l1 < l2)    remove(i);
            else            add(i);
        }
    };
    
    auto answer = [&](query q) {
        auto [freq, _] = *st.rbegin();
        if (freq > ((q.r - q.l + 1) - freq)) {
            return "usable";
        } else {
            return "unusable";
        }
    };

    vector<string> answers(M);
    int l = queries[0].l, r = l - 1;
    for (auto q: queries) {
        move(l, r, q.l, q.r);
        answers[q.i] = answer(q);
        l = q.l, r = q.r;
    }

    for (auto ans: answers) {
        assert(ans.length() >= 6);
        cout<<ans<<"\n";
    }
}