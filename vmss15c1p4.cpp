#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 2;

int t, n, m, g, ans;
vector<int> food;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> t >> n >> m >> g;

    while (g--) {
        int f; cin >> f;
        food.emplace_back(f);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    deque<int> q;
    q.emplace_back(0);

    memset(dist, 0x3f, sizeof(dist));

    dist[0] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (find(q.begin(), q.end(), v) == q.end()) q.emplace_back(v);
            }
        }
    }

    for (auto f : food) ans += (dist[f] <= t);

    cout << ans << '\n';
}
