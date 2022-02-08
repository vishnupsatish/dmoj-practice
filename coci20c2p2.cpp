#include <bits/stdc++.h>

using namespace std;

// Try to avoid double arithmetic and binary search for the
// answer. Use DSU to determine whether a given answer works.

#define int long long

const int MAXN = 1003;

struct Point {
    int x, y;
};

int n, dsu[MAXN];
vector<Point> a;


int find(int e) {
    if (dsu[e] != e) dsu[e] = find(dsu[e]);
    return dsu[e];
}


bool check(long double val) {
    val /= 1e8;

    for (int i = 0; i < n; i++) dsu[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y)) <= val * 2) dsu[find(i)] = find(j);
        }
    }

    int fst = find(0);

    for (int i = 1; i < n; i++) {
        if (find(i) != fst) return false;
    }

    return true;
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }

    int l = 0, r = 1e18;

    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << setprecision(8) << (long double)l / 1e8 << '\n';
}
