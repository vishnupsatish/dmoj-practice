#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/kCoYXRy

#define int long long

const int MAXN = 353, MOD = 1e9 + 7;

int num, memo[MAXN], dp[MAXN][MAXN], comb[MAXN][MAXN];


int fact(int numb) {
    if (numb <= 1) return 1ll;
    if (memo[numb] != 0) return memo[numb];
    return memo[numb] = (numb * fact(numb - 1ll)) % MOD;
}


int pow_mod(int x, int p) {
    if (p == 0) return 1ll;
    int c = pow_mod(x, p / 2ll) % MOD;
    if (p & 1ll) return (((c * c) % MOD) * x) % MOD;
    return (c * c) % MOD;
}


int choose(int n_, int r) {
    if (comb[n_][r]) return comb[n_][r];
    if (n_ < r) return 0;
    int numerator = fact(n_) % MOD;
    int denominator = (fact(r) * fact(n_ - r)) % MOD;
    return comb[n_][r] = (numerator * pow_mod(denominator, MOD - 2ll)) % MOD;
}


int solve(int k, int n) { // Given k tasks and n programmers, how many ways can we arrange the tasks so that at least one programmer is happy?
    if (dp[k][n] != -1) return dp[k][n];
    if (n == 0 || k == 0) return dp[k][n] = 0;

    int &ans = dp[k][n];
    ans = choose(k, n) * pow_mod(n - 1, k - n);
    ans %= MOD;

    for (int i = 0; i <= k; i++) {
        if (i == n) continue;
        ans += choose(k, i) * solve(k - i, n - 1);
        ans %= MOD;
    }

    return ans;
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> num;

    memset(dp, -1, sizeof(dp));

    cout << solve(num, num) << '\n';
}
