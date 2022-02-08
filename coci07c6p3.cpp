#include <bits/stdc++.h>

using namespace std;

const int MAXN = 103;

int n, a[MAXN], g;
unordered_set<int> ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (g == 0) g = abs(a[i] - a[i + 1]);
        else g = gcd(g, abs(a[i] - a[i + 1]));
    }

    for (int i = 2; i <= sqrt(g); i++) {
        if (g % i == 0) {
            ans.emplace(i);
            ans.emplace(g / i);
        }
    }

    if (g != 1) ans.emplace(g);

    bool f = true;

    for (auto e : ans) {
        if (!f) cout << ' ';

        cout << e;

        f = false;
    }

    cout << '\n';
}
