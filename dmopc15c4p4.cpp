#include <bits/stdc++.h>

using namespace std;

// Idea: PSA to answer first query, second query will be answered by
// lower_bound on a set containing all indices where a certain element appears

const int MAXN = 1e5 + 3;

int n, q, k, arr[MAXN], psa[MAXN];
unordered_map<int, set<int>> ind;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psa[i] = psa[i-1] + arr[i];
        ind[arr[i]].insert(i);
    }

    while (q--) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        auto index_a = ind[a].lower_bound(x);
        auto index_b = ind[b].lower_bound(x);
        if (index_a == ind[a].end() || index_b == ind[b].end()) cout << "No" << '\n';
        else if (psa[y] - psa[x-1] > k && *index_a <= y && *index_b <= y) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
