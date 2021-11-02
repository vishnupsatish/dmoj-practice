#include <bits/stdc++.h>

using namespace std;

const int MAXN = 503;

// Idea: if person a did better than person b, there is a directed edge
// from a to b. BFS N times to find the nodes you can't reach from the
// current node, and if the reverse is also true, and you can't say for
// certain who did better so increment ans.

int n, ans;
bool vis[MAXN], can_reach[MAXN][MAXN];
vector<int> adj[MAXN];


void bfs(int start) {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: adj[u]) {
            if (!vis[v]) {
                q.push(v);
                can_reach[start][v] = true;
                vis[v] = true;
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char a; cin >> a;
            int b = a - '0';
            if (b) adj[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans += ((!can_reach[i][j]) && (!can_reach[j][i]));
        }
    }

    cout << ans << '\n';
}
