#include <bits/stdc++.h>

using namespace std;

const int MAXAB = 1e7 + 2;

int T, sieve[MAXAB], primacity[MAXAB];
vector<int> primes;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> T;

    fill(begin(sieve), end(sieve), 1);
    sieve[0] = sieve[1] = 0;

    // Normal sieve
    for (long long i = 2; i * i <= 1e7; i++) {
        if (sieve[i]) {
            for (long long j = i * i; j <= 1e7; j += i) sieve[j] = 0;
        }
    }

    for (int i = 2; i <= 1e7; i++) {
        if (sieve[i]) primes.emplace_back(i);
    }

    // For all prime numbers, run a second sieve-like operation to increment the primacity
    for (auto p: primes) {
        for (int i = p; i <= 1e7; i += p) {
            primacity[i]++;
        }
    }

    for (int t = 1; t <= T; t++) {
        int a, b, k; cin >> a >> b >> k;

        int ans = 0;

        for (int i = a; i <= b; i++) {
            ans += (primacity[i] == k);
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}
