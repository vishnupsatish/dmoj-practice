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

// Idea: get coords of all Ms, run BFS, and increment by 1. If an M is vis, do not run BFS from there then

const int MAXRC = 100 + 3;

int r, c, vis[MAXRC][MAXRC];
char a[MAXRC][MAXRC];
int ans;


int bfs(pii st) {
    queue<pii> q;
    q.emplace(st);

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        int nr = u.fi, nc = u.se;

        vector<pii> adj;

        if (nr + 1 <= r && a[nr + 1][nc] != 'X' && !vis[nr + 1][nc]) adj.eb(nr + 1, nc);
        if (nr - 1 >= 1 && a[nr - 1][nc] != 'X' && !vis[nr - 1][nc]) adj.eb(nr - 1, nc);
        if (nc + 1 <= c && a[nr][nc + 1] != 'X' && !vis[nr][nc + 1]) adj.eb(nr, nc + 1);
        if (nc - 1 >= 1 && a[nr][nc - 1] != 'X' && !vis[nr][nc - 1]) adj.eb(nr, nc - 1);

        for (auto x : adj) {
            q.emplace(x);
            vis[x.fi][x.se] = true;
        }
    }

    return 1;
}


int main() {
    fastio();

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!vis[i][j] && a[i][j] != 'X') ans += bfs(mp(i, j));
        }
    }

    cout << ans << el;
}
