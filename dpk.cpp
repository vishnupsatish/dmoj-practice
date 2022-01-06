#include <bits/stdc++.h>

using namespace std;

int n, k;
unordered_set<int> a;
unordered_map<int, bool> dp;


// Returns 1 if the current player wins
bool play(int stones) {
    if (dp.contains(stones)) return dp[stones];
    if (stones == 0) return 0;
    bool win = false;
    for (auto s : a) {
        if (stones < s) continue;
        win |= !play(stones - s);
    }
    return dp[stones] = win;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int ai; cin >> ai; a.emplace(ai);
    }

    cout << (play(k) ? "First" : "Second") << '\n';
}
