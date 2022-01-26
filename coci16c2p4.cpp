#include <bits/stdc++.h>

using namespace std;

// Pattern observation exercise. If n is odd just go 1, 2, 3, ... n - 1, n.
// If n is even, try to make the n / 2 + 1th element the average for each row and column.

int n;

int main() {
    cin >> n;

    if (n == 2) {
        cout << -1 << '\n';
        return 0;
    }

    if (n & 1) {
        for (int i = 1; i <= n * n; i++) {
            cout << i << (i % n == 0 ? '\n' : ' ');
        }
        return 0;
    }

    int special, frs = 0, cur = 1, last_to_add = n / 2;

    for (int i = 1; i <= n; i++) {
        if (i == n) cur = special * n - frs;
        if (i == n / 2 + 1) special = cur;
        for (int j = 1; j < n; j++) {
            if (j == 1) frs += cur;
            cout << cur << ' ';
            cur++;
        }
        cur += last_to_add;
        cout << cur << '\n';
        cur++;
    }
}
