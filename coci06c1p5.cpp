#include <bits/stdc++.h>

using namespace std;


int n;
double p[21][21];
double dp[1 << 21];



double fun(int bond, int mask) {
    if (dp[mask] >= 0) return dp[mask];
    if (bond >= n) return 1.0;

    double ret = 0.0;
    for (int i=0; i<n; i++) {
        if ((mask & 1 << i) == 0) ret = max(ret, p[bond][i] * fun(bond + 1, mask | 1 << i));
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
            p[i][j] /= 100;
        }
    }
    cout << fixed << setprecision(9) << fun(0, 0) * 100 << endl;
}