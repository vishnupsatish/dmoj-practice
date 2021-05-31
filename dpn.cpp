#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define el "\n";

int n;
long long dp[402][402];
long long psa[402];
int ans = 0;


int main() {

    memset(dp, 0, sizeof(dp));

    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> dp[i][i];
        psa[i] = dp[i][i] + psa[i - 1];
    }

    for (int i=1; i+1<=n; i++) {
        dp[i][i+1] = dp[i][i] + dp[i+1][i+1] + dp[i+1][i+1] + dp[i][i];
    }

    for (int len=2; len<=n; len++) {
        for (int L=1; L+len<=n; L++) {
            int R = L + len;
            for (int m=L; m<R; m++) {
                dp[L][R] = dp[L][R] != 0 ? min(dp[L][R], dp[L][m] + (psa[m] - psa[L - 1]) + dp[m + 1][R] + (psa[R] - psa[m])) : dp[L][m] + (psa[m] - psa[L - 1]) + dp[m + 1][R] + (psa[R] - psa[m]);
            }
        }
    }

    cout << dp[1][n] - psa[n] << "\n";


    return 0;
}