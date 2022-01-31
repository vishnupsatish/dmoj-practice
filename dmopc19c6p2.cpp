#include <bits/stdc++.h>

using namespace std;

int a, b, ans = 1e9;
unordered_map<int, int> pfa;


void prime_factor(int x, unordered_map<int, int> &pf) {
    while (x % 2 == 0) {
        x /= 2;
        pf[2]++;
    }

    for (int i = 3; i <= sqrt(x); i += 2) {
        while (x % i == 0) {
            x /= i;
            pf[i]++;
        }
    }

    if (x > 2) pf[x]++;
}


int find_hp(int p, int x) { // Determine the highest power of p (a prime) that divides into x!
    int ret = 0;
    while (x != 0) {
        x /= p;
        ret += x;
    }
    return ret;
}



int main() {
    cin >> a >> b;

    prime_factor(a, pfa);

    for (auto [k, v] : pfa) {
        int hp = find_hp(k, b);
        ans = min(ans, hp / v);
    }

    cout << ans << '\n';
}
