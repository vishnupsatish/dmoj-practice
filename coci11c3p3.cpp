#include <bits/stdc++.h>

using namespace std;

int r, c, a[6]; // Up, down, right, left, forwards, backwards
long long ans;


vector<int> get_seq(bool dir) { // 1 for right, 0 for left
    if (dir) return {a[0], a[3], a[1], a[2]};
    else return {a[0], a[2], a[1], a[3]};
}


signed main() {
    cin >> r >> c;

    a[0] = 1; a[1] = 6; a[2] = 3; a[3] = 4; a[4] = 5; a[5] = 2;

    for (int i = 1; i <= r; i++) {
        vector<int> seq = get_seq(i & 1);

        ans += 14 * (c / 4);
        ans += accumulate(seq.begin(), seq.begin() + (c % 4), 0); // Remaining

        if (i & 1) { // Going right
            if (c % 4 == 0) { // Full sequence completes
                a[0] = seq[3]; a[3] = seq[0]; a[1] = seq[1]; a[2] = seq[2];
            } else if (c % 4 == 1) { // One extra (don't do anything)

            } else if (c % 4 == 2) { // Two extra
                a[0] = seq[1]; a[1] = seq[3]; a[2] = seq[0]; a[3] = seq[2];
            } else if (c % 4 == 3) { // Three extra
                a[0] = seq[2]; a[1] = seq[0]; a[2] = seq[1]; a[3] = seq[3];
            }
        } else { // Going left
            if (c % 4 == 0) { // Full sequence completes
                a[0] = seq[1]; a[3] = seq[2]; a[1] = seq[3]; a[2] = seq[0];
            } else if (c % 4 == 1) { // One extra (don't do anything)

            } else if (c % 4 == 2) { // Two extra
                a[0] = seq[1]; a[1] = seq[3]; a[2] = seq[2]; a[3] = seq[0];
            } else if (c % 4 == 3) { // Three extra
                a[0] = seq[0]; a[1] = seq[2]; a[2] = seq[3]; a[3] = seq[1];
            }
        }

        // Now we need to turn it up
        int t1 = a[0], t2 = a[1], t3 = a[4], t4 = a[5];

        a[0] = t3; a[1] = t4; a[5] = t1; a[4] = t2;
    }

    cout << ans << '\n';
}
