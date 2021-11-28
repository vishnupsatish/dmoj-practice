#include <bits/stdc++.h>

using namespace std;

// Fib sequence digits repeats when modded, but we don't know
// when. Create fib sequence, then hash to check when it repeats.

const int MAXN = 500000;
const int MOD = 1e9 + 7;

unordered_map<int, int> memo;

int m, q;
string fib;
long long hsh[MAXN], pw[MAXN], base = 131;

int fib_(int num) {
    if (memo.contains(num)) return memo[num];
    return memo[num] = (num == 1 || num == 2 ? 1 : (fib_(num - 1) % m + fib_(num - 2) % m) % m);
}

long long sub_hash(int l, int r) {
    return (hsh[r] - hsh[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> m >> q;

    for (int i = 1; i < 100000; i++) {
        fib += to_string(fib_(i) % m);
    }

    hsh[0] = 0; pw[0] = 1;

    for (int i = 1; i <= fib.length(); i++) {
        pw[i] = pw[i - 1] * base % MOD;
        hsh[i] = (hsh[i - 1] * base + fib[i - 1]) % MOD;
    }

    for (int i = m; i < fib.length() / 2; i++) {
        if (sub_hash(1, i) == sub_hash(i+1, 2*i)) {
            fib = fib.substr(0, i);
            break;
        }
    }

    while (q--) {
        long long n; cin >> n;
        n--;
        n %= (long long)fib.length();
        cout << fib[n] << '\n';
    }
}
