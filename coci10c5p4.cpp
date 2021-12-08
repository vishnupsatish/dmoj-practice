#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/hFPY4Uc

const int MAXN = 1e5 + 3;
const int MOD = 1e9 + 7;

int n;
long long a[MAXN], p[MAXN], dp[MAXN][2]

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> p[i];

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = ((dp[i - 1][0] * (a[i] + p[i - 1])) % MOD) + (dp[i - 1][1] * (a[i] + p[i - 1] - 1ll)) % MOD;
        dp[i][0] %= MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) * p[i];
        dp[i][1] %= MOD;
    }

    cout << dp[n][0] << '\n';
}
