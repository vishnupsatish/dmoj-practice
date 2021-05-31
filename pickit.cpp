#include <bits/stdc++.h>

using namespace std;

const int MM = 202;

int n;
int a[MM];
int dp[MM][MM];



int main() {

    while (true) {
        cin >> n; memset(dp, 0, sizeof(dp));
        if (n == 0) break;

        for (int i=1; i<=n; i++) cin >> a[i];

        for (int len=2; len<n;len++) {
            for(int l=1; l+len <= n; l++) {
                int r = l + len;
                for (int m=l+1; m<r; m++) {
                    dp[l][r] = max(dp[l][r], a[l] + a[m] + a[r] + dp[l][m] + dp[m][r]);
                }
            }
        }
        cout << dp[1][n] << endl;

    }

    return 0;
}