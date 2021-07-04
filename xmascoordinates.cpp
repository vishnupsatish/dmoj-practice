#pragma GCC optimize("Ofast", "unroll-loops")

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

#define fastio() cin.tie(0);ios::sync_with_stdio(0);
#define pii pair<int, int>
#define fi first
#define se second
#define pll pair<long long, long long>
#define mp make_pair
#define el "\n"
#define pq priority_queue
#define ll long long
#define ld long double
#define mt make_tuple
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define dq deque
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXN = 1e3 + 3;

int n, m, vis[MAXN][MAXN], dist[MAXN][MAXN];
char a[MAXN][MAXN];
pii st, ed, pres;


int bfs(pii start_pos, pii end_pos) {
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    queue<pii> q;
    q.emplace(start_pos);

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        int r = u.fi, c = u.se;
        if (u == end_pos) {
            return dist[r][c];
        }
        vector<pii> adj;
        if (r + 1 <= n && a[r + 1][c] != '#') adj.eb(r + 1, c);
        if (r - 1 >= 1 && a[r - 1][c] != '#') adj.eb(r - 1, c);
        if (c + 1 <= m && a[r][c + 1] != '#') adj.eb(r, c + 1);
        if (c - 1 >= 1 && a[r][c - 1] != '#') adj.eb(r, c - 1);
        for (auto v : adj) {
            if (!vis[v.fi][v.se]) {
                q.emplace(v);
                vis[v.fi][v.se] = 1;
                dist[v.fi][v.se] = dist[r][c] + 1;
            }
        }
    }
    return -1;
}


int main() {
    fastio();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'O') st = mp(i, j);
            else if (a[i][j] == 'X') ed = mp(i, j);
            else if (a[i][j] == 'P') pres = mp(i, j);
        }
    }


    int fidist = bfs(st, pres);

    if (fidist == -1) {
        cout << -1 << el; return 0;
    }

    int sedist = bfs(pres, ed);

    if (sedist == -1) {
        cout << -1 << el; return 0;
    }

    cout << fidist + sedist << el;
}
