#include <bits/stdc++.h>

using namespace std;

// I GOT SO CLOSE! I understood that adjacent nodes need to have a different polarity then the
// node itself since adjacent nodes are wrestlers that must be on different teams. I had to read
// the editorial to realize that you needed binary search to determine at which point the team
// arrangement becomes invalid.

const int MAXN = 1e5 + 3;

int n, m, vis[MAXN], pol[MAXN];
vector<pair<int, int>> f;
unordered_set<int> t1, t2;
vector<pair<int, int>> adj[MAXN];


void setup() {
    memset(vis, 0, sizeof(vis));
    memset(pol, -1, sizeof(pol));
    vis[1] = true;
}


bool dfs(int u, int val) {
    bool ok = true;

    for (auto [v, w] : adj[u]) {
        if (w > val) continue;

        if (pol[v] == -1) pol[v] = !pol[u];
        else if (pol[v] == pol[u]) return false;

        if (!vis[v]) {
            vis[v] = true;
            ok &= dfs(v, val);
        }
    }

    return ok;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    int l = 1, r = m;

    while (l < r) {
        setup();
        int mid = (l + r) >> 1;
        if (dfs(1, mid)) l = mid + 1;
        else r = mid;
    }

    cout << l << '\n';
}
