#include <bits/stdc++.h>

using namespace std;

// Observe that the answer is the sum of all the diameters of all of the 
// components; the total answer cannot be larger than this and we can 
// always connect the components in such a way that this is the answer.

const int MAXN = 1e5 + 3;

int n, m, dsu[MAXN], ans, mx_path, farthest;
vector<int> adj[MAXN];


int find(int e) {
    if (dsu[e] != e) dsu[e] = find(dsu[e]);
    return dsu[e];
}


void dfs(int u, int path, int par) {
    if (mx_path < path) {
        farthest = u;
        mx_path = path;
    }

    for (auto v : adj[u]) {
        if (v != par) dfs(v, path + 1, u);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) dsu[i] = i;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        dsu[find(u)] = find(v);
    }

    unordered_set<int> done;

    for (int i = 1; i <= n; i++) {
        if (!done.contains(find(i))) { // We haven't done this component yet
            mx_path = 0;
            farthest = 0;
            dfs(i, 0, -1);
            mx_path = 0;
            dfs(farthest, 0, -1);
            ans += mx_path + 1;
            done.insert(find(i));
        }
    }

    cout << ans << '\n';
}
