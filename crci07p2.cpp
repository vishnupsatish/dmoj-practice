#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1003;

int n, a[MAXN], dp[MAXN][MAXN];


int solve(int sq, int pre) {
    if (sq == n) return a[n];

    if (dp[sq][pre] != -1) return dp[sq][pre];

    int &ans = dp[sq][pre];
    ans = 1e9;

    if (pre < n - sq) { // We can jump forward
        ans = min(ans, solve(sq + pre + 1, pre + 1));
    }

    if (pre < sq) {
        ans = min(ans, solve(sq - pre, pre));
    }

    ans += a[sq];

    return ans;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(2, 1) << '\n';
}
