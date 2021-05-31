#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
int psa[402];
int dp[402][402];
int ans = 0;


int main() {

    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> psa[i];
        ans = max(ans, psa[i]);
        psa[i] += psa[i - 1]; dp[i][i] = true;
    }

    for (int len=1; len<n; len++) {
        for (int L=1; L + len <= n; L++) {
            int R = L + len;
            for (int p=L, q=R; p<q;) {
                int sumL = psa[p] - psa[L - 1];
                int sumR = psa[R] - psa[q - 1];
                if (dp[L][p] && dp[q][R] && p + 1 == q && sumL == sumR) { // op1
                    dp[L][R] = true;
                }
                else if (dp[L][p] && dp[q][R] && dp[p + 1][q - 1] && sumL == sumR) { // op2
                    dp[L][R] = true;
                }
                if (dp[L][R]) ans = max(ans, psa[R] - psa[L - 1]);
                if (sumL < sumR) p++;
                else q--;
            }
        }
    }
    cout << ans << endl;


    return 0;
}