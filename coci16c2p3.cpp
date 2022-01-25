#include <bits/stdc++.h>

using namespace std;

// Idea: two pointers, left and right. If a[l] == a[r] then increment l and 
// decrement r, since we don't need to join those. If a[l] < a[r], then we 
// need to combine a[l] and a[l + 1], then increment l. Same for r.

const int MAXN = 1e6 + 2;

int n, ans, a[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    int l = 1, r = n;

    while (l <= r) {
        if (a[l] == a[r]) {
            l++;
            r--;
        } else if (a[l] < a[r]) {
            a[l + 1] += a[l];
            l++;
            ans++;
        } else {
            a[r - 1] += a[r];
            r--;
            ans++;
        }
    }

    cout << ans << '\n';
}
