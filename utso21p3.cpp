#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 3;

const int MOD = 1e9 + 7;

int n, m_so_far, ind;
long long so_far, dp[MAXN];

int main() {
    cin >> n;
    dp[0] = 1;
    so_far = 1;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a > m_so_far) {
            dp[i] = so_far;
            ind = i;
            m_so_far = a;
        } else if (a < m_so_far) {
            dp[i] = dp[ind];
        } else {
            dp[i] = (dp[ind] * (i - ind + 1)) % MOD;
            ind = i;
        }
        so_far += dp[i];
        so_far %= MOD;
    }
    
    cout << dp[n] << '\n';
}
