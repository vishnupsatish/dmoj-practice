#include <bits/stdc++.h>

using namespace std;

// Idea: use a BIT to determine whether a given cord and all roombas intersect.
// When we are at a certain x point, we know some roombas can be ignored, so remove
// them from the BIT (to be specific, their y values).Use coordinate compression to make
// all elements fit within the range [1, 4e5]. Line sweep all x values from all roombas
// and cords so we don't need to iterate 1e9 times.

const int MAXXY = 4e5 + 2;

int n, m, ys[MAXXY];
long long ans;
set<int> all_xs, all_ys;
unordered_map<int, int> cords_x; // Maps x -> y of a cord
unordered_map<int, vector<int>> roombas_x; // Maps x -> all ys of a roomba
unordered_map<int, int> coord_compress;// Compress all y coordinates to fit in the range [1, 4e5]
unordered_set<int> roombas_y;


int sum(int i, int (&arr)[MAXXY]) {
    int ret = 0;
    while (i > 0) {
        ret += arr[i];
        i -= (i & -i); // Flip the last set bit
    }
    return ret;
}

void change(int i, int add, int (&arr)[MAXXY], int end) {
    while (i < end) {
        arr[i] += add;
        i += (i & -i);
    }
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        all_xs.emplace(x);
        all_ys.emplace(y);
        roombas_x[x].emplace_back(y);
        roombas_y.emplace(y);
    }

    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        all_xs.emplace(x);
        all_ys.emplace(y);
        cords_x[x] = y;
    }

    int cnt = 1;
    for (auto y: all_ys) {
        coord_compress[y] = cnt;
        if (roombas_y.contains(y)) {
            ys[cnt]++;
        }
        cnt++;
    }

    // Build BIT
    for (int i = 1; i < MAXXY; i++) {
        int par = i + (i & -i);
        if (par < MAXXY) ys[par] += ys[i];
    }
    // End build

    for (auto i: all_xs) {
        if (cords_x.contains(i)) {
            ans += (long long)sum(coord_compress[cords_x[i]], ys);
        }
        if (roombas_x.contains(i)) {
            for (auto y_roomba: roombas_x[i]) {
                change(coord_compress[y_roomba], -1, ys, MAXXY);
            }
        }
    }

    cout << ans << '\n';
}
