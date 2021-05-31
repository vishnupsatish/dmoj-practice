#include <bits/stdc++.h>

using namespace std;


int n;
int p[21][21];
int dp[1 << 21];

int func(int man, int mask) {
    if (dp[mask] >= 0) return dp[mask];
    if (man >= n) return 1;

    int ret = 0;
    for (int i=0; i<n; i++) {
        if ((mask & 1 << i) == 0) ret += p[man][i] * func(man + 1, mask | 1 << i);
        ret %= 1000000007;
    }
    dp[mask] = ret;
    return dp[mask];
}


int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }

    cout << func(0, 0) << endl;

}