#include <bits/stdc++.h>

using namespace std;

const int MAXM = 30003, MAXN = 1003;

int m, n, k, d[MAXM][MAXN];

// Idea: 1D difference array, one for each north-south road, O(N) for each circle.
// Use Pythagorean theorem to determine the height of the maximum and minimum points
// current circle will reach, difference array update there.

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> m >> n >> k;

    while (k--) {
        int x, y, r, b; cin >> x >> y >> r >> b;
        for (int i = max(1, x - r); i <= min(n, x + r); i++) {
            int h = sqrt((r * r) - (abs(x - i) * abs(x - i)));
            d[max(1, y - h)][i] += b; d[min(y + h + 1, MAXM - 1)][i] -= b;
        }
    }

    int ma = 0, no_of_ma = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[j][i] += d[j - 1][i];
            ma = max(ma, d[j][i]);
        }
    }

    cout << ma << "\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            no_of_ma += (d[j][i] == ma);
        }
    }

    cout << no_of_ma << "\n";
}