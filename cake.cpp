#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 2;

int n, m, k, q;

long long psa[MAXN][MAXN], a[MAXN][MAXN];


long long query(int x1, int y1, int x2, int y2) {
    return psa[y2][x2] - psa[y2][x1 - 1] - psa[y1 - 1][x2] + psa[y1 - 1][x1 - 1];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> k;

    while (k--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        a[y1][x1]++; a[y2 + 1][x2 + 1]++; a[y1][x2 + 1]--; a[y2 + 1][x1]--;
    }

    // The array is flipped upside-down, we need to "PSA" our 2D difference array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] + a[i][j] - a[i - 1][j - 1];
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] + a[i][j] - psa[i - 1][j - 1];
        }
    }

    cin >> q;

    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << '\n';
    }
}
