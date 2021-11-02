#include <bits/stdc++.h>

using namespace std;

// Idea: calculate the total sum of all maximum values of
// all subsequences, and do the same for all minimum values
// in all subsequences. Use monostack for this.

const int MAXN = 3e5 + 3;

int n;
long long total_max, total_min, h[MAXN], l_index_max[MAXN], r_index_max[MAXN], l_index_min[MAXN], r_index_min[MAXN];

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> h[i];

    // Find l_index_max for each h using monotonically decreasing stack.
    vector<pair<int, int>> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && stk.back().first < h[i]) stk.pop_back();
        if (stk.empty()) l_index_max[i] = 0;
        else l_index_max[i] = stk.back().second;
        stk.emplace_back(h[i], i);
    }

    // Find l_index_min for each h using monotonically decreasing stack.
    stk.clear();
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && stk.back().first > h[i]) stk.pop_back();
        if (stk.empty()) l_index_min[i] = 0;
        else l_index_min[i] = stk.back().second;
        stk.emplace_back(h[i], i);
    }

    // Find r_index_min for each h using monotonically decreasing stack.
    stk.clear();
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && stk.back().first >= h[i]) stk.pop_back();
        if (stk.empty()) r_index_min[i] = n+1;
        else r_index_min[i] = stk.back().second;
        stk.emplace_back(h[i], i);
    }

    // Find r_index_max for each h using monotonically decreasing stack.
    stk.clear();
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && stk.back().first <= h[i]) stk.pop_back();
        if (stk.empty()) r_index_max[i] = n+1;
        else r_index_max[i] = stk.back().second;
        stk.emplace_back(h[i], i);
    }

    for (long long i = 1; i <= n; i++) {
        total_max += ((h[i]) * (i - l_index_max[i]) * (r_index_max[i] - i));
    }

    for (long long i = 1; i <= n; i++) {
        total_min += ((h[i]) * (i - l_index_min[i]) * (r_index_min[i] - i));
    }

    cout << total_max - total_min << "\n";
}