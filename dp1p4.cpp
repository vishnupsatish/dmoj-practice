#include <bits/stdc++.h>

using namespace std;

// Pattern finding in the DP table

const int MAXN = 1e5 + 2;
const int MOD = 1e4 + 7;

string a;

int dp[MAXN];
unordered_map<char, int> so_far;

signed main() {
    cin >> a;

    int n = a.size();

    dp[0] = 1;
    so_far[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]);
        else if (so_far.contains(a[i])) dp[i] = dp[i - 1] * 2 - so_far[a[i]];
        else dp[i] = (dp[i - 1] * 2 + 1);
        dp[i] %= MOD;
        so_far[a[i]] = dp[i - 1];
    }

    cout << dp[n - 1] << '\n';
}
