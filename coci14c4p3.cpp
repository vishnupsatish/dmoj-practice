#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/XrTro5U

int n, ma;
long long s;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ma = max(a, ma);
        s += a;
    }

    cout << (ma > s / 2ll ? 2 * ma : s) << '\n';
}
