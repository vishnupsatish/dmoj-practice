#include <bits/stdc++.h>

using namespace std;

int N, p, dp[2002][2002][2]; vector<int> x;

typedef long long ll;


int main() {
    cin >> N >> p; x.resize(N + 1);

    for (int i =0; i<N; i++) {
        cin >> x[i];
    }

    x[N] = p; N++; sort(x.begin(), x.end());
    int st = lower_bound(x.begin(), x.end(), p) - x.begin();
    memset(dp, 0x3f, sizeof(dp));
    dp[st][st][0] = dp[st][st][1] = 0;

    for (int len=1; len < N; len++) {
        for (int L=0; L + len < N; L++) {
            int R = L + len;
            dp[L][R][0] = min(dp[L+1][R][0] + 1LL * (x[L + 1] - x[L]) * (N - len),
                              dp[L+1][R][1] + 1LL * (x[R] - x[L]) * (N - len));
            dp[L][R][1] = min(dp[L][R - 1][0] + 1LL * (x[R] - x[L]) * (N-len),
                              dp[L][R - 1][1] + 1LL * (x[R] - x[R - 1]) * (N - len));
        }
    }

    cout << min(dp[0][N - 1][0], dp[0][N - 1][1]) << endl;


}