#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
long long dp[3002][3002];
long long psa[3002];


int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i]; psa[i] = dp[i][i] + psa[i - 1];
    }

    for (int len=1; len<n; len++) {
        for (int L=1; L+len <= n; L++) {
            int R = L + len;
            dp[L][R] = psa[R] - psa[L - 1] - min(dp[L + 1][R], dp[L][R - 1]);
        }
    }

    long long taro = dp[1][n];
    long long jiro = psa[n] - dp[1][n];
    cout << taro - jiro;

    return 0;
}