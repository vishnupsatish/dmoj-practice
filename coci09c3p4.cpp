#include <bits/stdc++.h>

#define int long long

using namespace std;

// Idea: https://imgur.com/a/AgJpm9U

const int MAXN = 1e5 + 3;
const int MAXSQRTN = 1e3;

int n, m, len, a[MAXN], rangemin[MAXSQRTN];
vector<pair<int, int>> tmp;


// From CP-algos
int rmq(int l, int r) {
    int ret = MAXN - 1; // *
    for (int i=l; i<=r; )
        if (i % len == 0 && i + len - 1 <= r) {
            // if the whole block starting at i belongs to [l, r]
            if (a[rangemin[i / len]] < a[ret]) ret = rangemin[i / len];
            i += len;
        }
        else {
            if (a[i] < a[ret]) ret = i;
            ++i;
        }
    return ret;
}


int solve(int l, int r, int mi) {
    if (l == r) return a[l] - mi;
    int rm = rmq(l, r);
    if (rm == l) return solve(rm + 1, r, a[rm]) + a[rm] - mi;
    if (rm == r) return solve(l, rm - 1, a[rm]) + a[rm] - mi;
    return solve(l, rm - 1, a[rm]) + solve(rm + 1, r, a[rm]) + a[rm] - mi; // Once the min element is found, that's the max number of calls you can perform in that range
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int p_, c; cin >> p_ >> c;
        tmp.emplace_back(p_, c);
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < n; i++) { // Why do we need to consider m? coordinate compress. now m = n + 1.
        a[i] = tmp[i].second;
    }

    fill(begin(rangemin), end(rangemin), -1);

    // Taken from CP-algos: build RMQ
    len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks

    for (int i=0; i<n; ++i)
        if (a[i] < a[rangemin[i / len]] || rangemin[i/len] == -1)
            rangemin[i / len] = i;

    a[MAXN - 1] = 1e9 + 5; // *: Hack
    // End build

    cout << solve(0, n - 1, 0) << '\n';
}
