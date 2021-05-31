#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define el "\n";

int N;
int dp[102][102];
int a[102];
int ans = 0;


int main() {

    memset(dp, 0, sizeof(dp));

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        dp[i][i] = a[i] % 2 == 1 ? 1 : 0;
    }

    for (int len = 1; len < N; len++) {
        for (int L = 1; L + len <= N; L++) {
            int R = L + len;
            dp[L][R] = max(dp[L][L] - dp[L + 1][R], dp[R][R] - dp[L][R - 1]);
        }
    }


    for (int len = -N + 1; len <= -1; len++) {
        for (int L = N; L + len >= 1; L--) {
            int R = L + len;

            int p1 = dp[L][L] - dp[L + 1][R];
            int p2 = dp[R][R] - dp[L][R - 1];
            if (L == N) {
                p1 = dp[L][L] - dp[1][R];
            }
            if (R == 1) {
                p2 = dp[R][R] - dp[L][N];
            }

            dp[L][R] = max(p1, p2);
        }
    }



    if (dp[2][N] + (a[1] % 2) > 0) {
        ans += 1;
    }

    for (int i = 2; i < N; i++) {
        if (dp[i + 1][i - 1] + (a[i] % 2) > 0) {
            ans += 1;
        }
    }

    if (dp[1][N - 1] + (a[N] % 2) > 0) {
        ans += 1;
    }


    cout << ans << el;


    return 0;
}