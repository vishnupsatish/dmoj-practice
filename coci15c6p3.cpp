#include <bits/stdc++.h>

using namespace std;

// Idea: create an array that determines how the original array increases
// and decreases. Based on that array, you can calculate what value of K
// would allow a[i] to be present in the keys pressed, then choose the max
// K out of each element. This is allowed because she doesn't compare what
// she plays with what is in the composition.

const int MAXN = 1e6 + 3;

int n, a[MAXN], to_add, dn, tot, val;
unordered_map<int, int> ans;


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) val++;
        else if (a[i - 1] > a[i]) val--;

        if (val == 0 && a[i] == a[1]) to_add++;
        else if (val != 0 && (a[i] - a[1]) % val == 0) {
            ans[(a[i] - a[1]) / val]++;
        }
    }

    for (auto [k, v] : ans) {
        if (v > tot) {
            tot = v;
            dn = k;
        }
    }

    cout << tot + to_add + 1 << '\n' << dn << '\n';
}
