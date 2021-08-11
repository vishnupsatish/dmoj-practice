#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>
#endif

#define fastio() cin.tie(0);ios::sync_with_stdio(0);
#define fi first
#define se second
#define el "\n"
#define ll long long
#define ld long double
#define vi vector<int>
#define eb emplace_back
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

// Idea: BFS from every node to every other node, store answer in ans 2d array

const int MAXN = 1e3 + 3;

int n, m, t, q_, ans[MAXN][MAXN], vis[MAXN];
vector<int> adj[MAXN];


void bfs(int start) {
    memset(vis, 0, sizeof(vis));

    queue<int> q;

    vis[start] = 1;
    q.emplace(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                ans[start][v] = ans[start][u] + t;
                q.emplace(v);
            }
        }
    }
}


int main() {
    fastio();

    cin >> n >> m >> t;

    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].eb(v);
    }

    for (int i = 1; i <= n; i++) bfs(i);

    cin >> q_;
    while (q_--) {
        int u, v; cin >> u >> v;
        if (!ans[u][v]) cout << "Not enough hallways!" << el;
        else cout << ans[u][v] << el;
    }
}
