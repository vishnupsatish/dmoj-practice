#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<pi> adj[18];
int u, v, w;

int dp[18][1 << 18];


int fun(int u, int mask) {
    if (dp[u][mask] >= 0) return dp[u][mask];
    if (u == n - 1) return 0;
    for (pi e : adj[u]) {
        int v = e.first, w = e.second;
        if ((mask & 1 << v) == 0) {
            dp[u][mask] = max(dp[u][mask], w + fun(v, mask | 1 << v));
        }
    }
    return dp[u][mask];
}


int main() {
    cin >> n >> m;
    memset(dp, -0x3f, sizeof(dp));
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w; adj[u].push_back({v, w});
    }
    cout << fun(0, 1) << endl;
}