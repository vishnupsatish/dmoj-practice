#include <bits/stdc++.h>

using namespace std;

// Max impulses of a gives tree will always be 1, since we can direct an edge to its child,
// then direct the edge from the child's child to the child itself, meaning they can't go any
// further. Run a DFS then flip the polarity of a node based on its parent so a node's
// polarity will be different from its parent's and child's, then depending on the first
// node's polarity for each edge, direct it one way or the other

const int MAXN = 1e5 + 3;

int n, p[MAXN]; // "Polarity"
vector<int> adj[MAXN];
vector<pair<int, int>> edges;


void dfs(int u, int parent) {
    p[u] = !p[parent];
    for (auto v: adj[u])
        if (v != parent) dfs(v, u);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        edges.emplace_back(a, b);
    }

    dfs(1, 0);

    for (auto [a, b]: edges) cout << (int)(p[a] & 1) << '\n';
}
