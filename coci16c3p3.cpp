#include <bits/stdc++.h>

using namespace std;

// Idea: bitmask DP: mask represents the subset of glasses that
// have no water (1). All the water is in the glasses with water (0).
// Determine the min effort needed to get to the point where the 
// number of glasses with water is == k

const int MAXN = 22;

int n, k, c[MAXN][MAXN], dp[1 << MAXN];


int f(unsigned int mask) {
    // We want to determine the min effort to get to when the
    // number of glasses with water is == k, so make this the base case
    if (n - popcount(mask) == k) return 0;

    if (dp[mask] != 1e9) return dp[mask];

    for (int i = 0; i < n; i++) { 
        if (mask & 1 << i) continue; // If i has no water, we cannot move water away from it
        for (int j = 0; j < n; j++) { // Move water from i to j
            if (i == j) continue;
            if (!(mask & 1 << j)) { // If j has no water, why move water to it? Not optimal
                dp[mask] = min(dp[mask], f(mask | 1 << i) + c[i][j]);
            }
        }
    }

    return dp[mask];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    fill(begin(dp), end(dp), 1e9);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    cout << f(0) << '\n';
}
