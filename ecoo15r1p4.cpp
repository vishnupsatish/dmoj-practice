#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1002;

// DP

string s;
int dp[MAXN];
unordered_set<string> nums = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 10;
    while (t--) {
        fill(begin(dp), end(dp), 1e9);
        cin >> s;

        dp[0] = 1;

        s = '0' + s;

        for (int i = 1; i < s.size(); i++) {
            for (const auto &c : nums) {
                if (i >= c.size() && s.substr(i - c.size()+1, c.size()) == c) {
                    if (dp[i - c.size()] < 1000000000) {
                        if (dp[i] == 1000000000) dp[i] = 0;
                        dp[i] += dp[i - c.size()];
                    }
                }
            }
        }

        if (dp[s.size() - 1] >= 1000000000) cout << 0 << '\n';
        else cout << dp[s.size() - 1] << '\n';
    }
}
