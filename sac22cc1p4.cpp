#include <bits/stdc++.h>

using namespace std;

// DP: dp[x][y][z] represents the number of increasing subsequences ending at or before index x with length y and sum of z. y <= 3 and z <= max element in A.

const int MAXN = 1e5 + 3;

int n, a[MAXN];
long long ans, dp[4][103], p[4][103];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    p[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k <= 100; k++) {
                dp[j][k] = p[j][k];
                if (k >= a[i] && j >= 1) dp[j][k] += p[j - 1][k - a[i]];
            }
        }
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k <= 100; k++) {
                p[j][k] = dp[j][k];
            }
        }
        ans += p[3][a[i]];
    }

    cout << ans << '\n';
}
