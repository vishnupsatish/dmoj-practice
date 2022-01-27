#include <bits/stdc++.h>

using namespace std;

// Binary search for answer. An answer works if you greedily chose elements to
// be paired and that works. If an answer works, then all above will work too.

const int MAXNM = 1e5 + 3;

int n, m, l[MAXNM], r[MAXNM];


bool ok(int val) {
    int pt = 1;

    for (int i = 1; i <= n; i++) {
        if (abs(r[pt] - l[i]) <= val) pt++;
        if (pt == m + 1) return true;
    }

    return pt == m + 1;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    if (n >= m) {
        for (int i = 1; i <= n; i++) cin >> l[i];
        for (int i = 1; i <= m; i++) cin >> r[i];
    } else {
        for (int i = 1; i <= n; i++) cin >> r[i];
        for (int i = 1; i <= m; i++) cin >> l[i];
        swap(n, m);
    }

    sort(l + 1, l + n + 1);
    sort(r + 1, r + m + 1);

    int lp = 0, rp = 1e9;

    while (lp < rp) {
        int mid = (lp + rp) >> 1;
        if (ok(mid)) rp = mid;
        else lp = mid + 1;
    }

    cout << lp << '\n';
}
