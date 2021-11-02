#include <bits/stdc++.h>

using namespace std;

// Idea: use the magic that is the binary indexed tree. 2 bits, one for the actual sums and the
// other for the other type of query. pray to https://www.youtube.com/watch?v=uSFzHCZ4E-8.

const int MAXN = 1e5 + 5;

int n, m, a[MAXN];
long long bit[MAXN+2], cnt[MAXN+2];


long long sum(int i, long long (&arr)[MAXN+2]) {
    long long ret = 0;
    while (i > 0) {
        ret += arr[i];
        i -= (i & -i); // Flip the last set bit
    }
    return ret;
}


void change(int i, long long add, long long (&arr)[MAXN+2], int end) {
    while (i <= end) {
        arr[i] += add;
        i += (i & -i);
    }
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i]; bit[i] = a[i];
        cnt[a[i]]++; // Use second BIT to find min element
    }

    for (int i = 1; i <= n; i++) {
        int par = i + (i & -i); // Add the last set bit to find parent of the current node
        if (par <= n) bit[par] += bit[i];
    }

    for (int i = 1; i <= MAXN - 3; i++) {
        int par = i + (i & -i); // Add the last set bit to find parent of the current node
        if (par <= MAXN - 3) cnt[par] += cnt[i];
    }

    while (m--) {
        char q; cin >> q;
        if (q == 'C') {
            int ind, val; cin >> ind >> val;
            change(a[ind], -1, cnt, MAXN - 3);
            change(ind, val - a[ind], bit, n);
            a[ind] = val;
            change(val, 1, cnt, MAXN - 3);
        } else if (q == 'S') {
            int i, j; cin >> i >> j;
            cout << sum(j, bit) - sum(i - 1, bit) << '\n';
        } else {
            int val; cin >> val;
            cout << sum(val, cnt) << '\n';
        }
    }
}
