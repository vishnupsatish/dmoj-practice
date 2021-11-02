#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;

    long long a_gcd; cin >> a_gcd;

    // Get GCD
    for (int i = 2; i <= n; i++) {
        long long a; cin >> a; a_gcd = gcd(a_gcd, a);
    }

    // Prime factorize
    long long ans = 0;

    while (a_gcd != 1 && a_gcd % 2 == 0) {
        a_gcd /= 2;
        ans = 2;
    }

    for (long long i = 3; i <= sqrt(a_gcd) + 1; i += 2) {
        while (a_gcd % i == 0) {
            a_gcd /= i;
            ans = i;
        }
    }

    ans = max(ans, a_gcd);

    if (ans == 1) cout << "DNE" << "\n";
    else cout << ans << "\n";
}