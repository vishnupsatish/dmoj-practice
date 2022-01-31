#include <bits/stdc++.h>

using namespace std;

// Idea: c * (c + 1) * ... * d must divide into a * (a + 1) * ... * b. Change it to be d!/(c - 1)!
// must be divisible by b!/(a - 1)!. If this is to be true, for each prime, the highest power of the
// prime that divides into d!/(c - 1)! must be greater than or equal to the highest power of the prime
// that divides into b!/(a - 1)!

const int MAXVAL = 1e7 + 3;

int t, sieve[MAXVAL];
vector<int> prime;


// Find all primes from 1 to 1e7
void build() {
    fill(begin(sieve), end(sieve), 1);

    sieve[0] = sieve[1] = 0;

    for (int i = 2; i * i <= 1e7; i++) {
        if (sieve[i]) { // Number is prime
            for (int j = i * i; j <= 1e7; j += i) {
                sieve[j] = 0;
            }
        }
    }

    for (int i = 2; i <= 1e7; i++) {
        if (sieve[i]) prime.emplace_back(i);
    }
}


int hp(int p, int x) { // Determine the highest power of p (a prime) that divides into x!
    int ans = 0;
    while (x != 0) {
        x /= p;
        ans += x;
    }
    return ans;
}


void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    bool ok = true;

    for (auto p : prime) {
        if (hp(p, b) - hp(p, a - 1) > hp(p, d) - hp(p, c - 1)) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "DA" : "NE") << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> t;

    build();

    while (t--) solve();
}
