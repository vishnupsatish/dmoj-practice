#include <algorithm>
#include <string>
#include <iostream>
#include <numeric>

using namespace std;

int N;

int dp[302][302];
int color[302];


int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> color[i]; dp[i][i] = 1;
    }

    for (int len = 1; len < N; len++) {
        for (int L = 1; L + len <= N; L++) {
            int R = L + len; dp[L][R] = 303;
            for (int m = L; m < R; m++) {
                dp[L][R] = min(dp[L][R], dp[L][m] + dp[m + 1][R]);
            }
            if (color[L] == color[R]) {
                dp[L][R] = min(dp[L][R], min(dp[L][R - 1], dp[L+1][R]));
            }
        }
    }

    cout << dp[1][N] << endl;

}