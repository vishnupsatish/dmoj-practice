#include <bits/stdc++.h>

using namespace std;

// Idea: Figure out using a pattern that only the element k -> end works for largest number;
// then figure out that each largest element will appear N-i-1 choose k - 1 times where i is
// the index of the element, in reverse. Since when that element must be there, there are k - 1
// elements left to fill up the remaining k - 1 spots, and N-i-1 elements to pick from, excluding
// the current one and any larger ones, then use choose with mod.

#define int long long

const int MAXN = 1e5 + 3;
const int MOD = 1e9 + 7;

int n, k, a[MAXN];
int memo[MAXN];


int fact(int numb) {
    if (numb == 1) return 1;
    if (memo[numb] != 0) return memo[numb];
    return memo[numb] = (numb * fact(numb - 1)) % MOD;
}


int pow_mod(int x, int p) {
    if (p == 0) return 1;
    int c = pow_mod(x, p / 2) % MOD;
    if (p & 1) return (((c * c) % MOD) * x) % MOD;
    return (c * c) % MOD;
}


int choose(int n_, int r) {
    int numerator = fact(n_) % MOD;
    int denominator = (fact(r) * fact(n_ - r)) % MOD;
    return (numerator * pow_mod(denominator, MOD - 2)) % MOD;
}


signed main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(begin(a)+1, begin(a)+1+n);

    vector<int> nums;

    for (int i = n; i >= k; i--) {
        nums.emplace_back(a[i]);
    }

    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        int cur;
        if (k == 1) cur = 1;
        else if (n - i - 1 == 0) cur = 0;
        else if (n - i - 1 != k - 1) cur = choose(n - i - 1, k - 1) % MOD;
        else cur = 1;
        ans += (cur * nums[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}
