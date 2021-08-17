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

// Idea: BFS from start point and store time when it reaches all of the gift sell places, and do the same for the end point

const int MAXN = 100003;

int n, m, k, a, b, vis[MAXN], dist_a[MAXN], dist_b[MAXN], ans = INF;
vi adj[MAXN];
vi s;

int main() {
    fastio();

    cin >> n >> m >> k >> a >> b;

    for (int i = 1; i <= k; i++) {
        int c; cin >> c; s.eb(c);
    }

    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }

    deque<int> q;
    q.eb(a);
    vis[a] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.eb(v);
                dist_a[v] = dist_a[u] + 1;
            }
        }
    }

    memset(vis, 0, sizeof(vis));

    q.clear();

    q.eb(b);
    vis[b] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.eb(v);
                dist_b[v] = dist_b[u] + 1;
            }
        }
    }

    for (auto u : s) {
        ans = min(ans, dist_a[u] + dist_b[u]);
    }

    cout << ans << el;
}
