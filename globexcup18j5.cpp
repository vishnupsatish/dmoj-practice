#include <bits/stdc++.h>

using namespace std;

// Idea: BFS from C to every other node

const int MAXN = 1e5 + 3;

int n, m, q, c, dist[MAXN], vis[MAXN];
vector<int> adj[MAXN];

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> n >> m >> q >> c;

    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    queue<int> qu;
    qu.push(c);
    vis[c] = 1;
    fill(begin(dist), end(dist), 1e9);
    dist[c] = 0;

    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        if (dist[u] == (int)1e9 || dist[v] == (int)1e9) cout << "This is a scam!" << '\n';
        else cout << dist[u] + dist[v] << '\n';
    }
}
