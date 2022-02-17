#include <bits/stdc++.h>

using namespace std;

// Idea: binary search for the number of seconds. Determine how many coconuts can be found
// by the first type in S seconds and how many can be opened by the second type in T - S
// seconds. If how many coconuts can be opened is greater than or equal to how many can be
// found, you have found your answer. (find the largest answer).

#define int long long

const int MAXN = 103;

int n, m, t, a[MAXN], b[MAXN], c[MAXN], d[MAXN];


// Check how many coconuts can be found by type 1 in s seconds
int check_1(int s) {
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += (s >= a[i]);
        ans += max(0ll, (s - a[i]) / b[i]);
    }

    return ans;
}


// Check how many coconuts can be opened by type 2 in s seconds
int check_2(int s) {
    int ans = 0;

    for (int i = 1; i <= m; i++) {
        ans += (s >= c[i]);
        ans += max(0ll, (s - c[i]) / d[i]);
    }

    return ans;
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> t;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }

    int l = 1, r = t;

    while (l < r) {
        int mid = (l + r) / 2;

        if (check_1(mid) > check_2(t - mid)) r = mid;
        else l = mid + 1;
    }

    cout << l - 1 << '\n';
}
