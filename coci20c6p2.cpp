#include <bits/stdc++.h>

using namespace std;

// 👨‍🌾

const int MAXN = 3003;

int n, m, queries, cnt;
long long dist[MAXN][MAXN];
bool memo[MAXN];
vector<pair<int, int>> adj[MAXN];
unordered_map<string, int> mp; // Maps a word to an integer


void sssp(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    q.emplace(0, start);

    fill(begin(dist[start]), end(dist[start]), (long long)1e18);
    dist[start][start] = 0ll;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        for (auto [v, w] : adj[u]) {
            if (dist[start][u] + w < dist[start][v]) {
                dist[start][v] = dist[start][u] + w;
                q.emplace(w, v);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        string u, v; int w; cin >> u >> v >> w;

        if (!mp.contains(u)) mp[u] = cnt++;
        if (!mp.contains(v)) mp[v] = cnt++;

        adj[mp[u]].emplace_back(mp[v], w);
    }

    cin >> queries;

    while (queries--) {
        string u, v; cin >> u >> v;

        if (!memo[mp[u]]) sssp(mp[u]);

        cout << (dist[mp[u]][mp[v]] == (long long)1e18 ? "Roger" : to_string(dist[mp[u]][mp[v]])) << '\n';
    }
}
