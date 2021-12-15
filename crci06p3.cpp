#include <bits/stdc++.h>

using namespace std;

// Use PSA

const int MAXH = 5e5 + 3;

int n, h, ans = 1e9, cnt;
int psab[MAXH], psat[MAXH];

int main() {
    cin >> n >> h;

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        if (i & 1) psab[c]++;
        else psat[h - c + 1]++;
    }

    for (int i = h; i >= 1; i--) psab[i] += psab[i + 1];

    for (int i = 1; i <= h; i++) psat[i] += psat[i - 1];

    for (int i = 1; i <= h; i++) ans = min(ans, psat[i] + psab[i]);

    for (int i = 1; i <= h; i++) if (ans == psat[i] + psab[i]) cnt++;

    cout << ans << ' ' << cnt << '\n';
}
