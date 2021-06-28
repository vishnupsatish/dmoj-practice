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

const int MAXN = 27;

int n, q, vis[MAXN][MAXN], cur_ind[MAXN][MAXN];
char a[MAXN][MAXN];


bool bfs(string s, pii start) {

    if (s[0] != a[start.fi][start.se]) return false;

    memset(vis, 0, sizeof(vis));
    memset(cur_ind, 0, sizeof(cur_ind));
    queue<pii> qu;
    qu.emplace(start);
    vis[start.fi][start.se] = 1;


    while (!qu.empty()) {
        pii u = qu.front(); qu.pop();
        int r = u.fi; int c = u.se;

        vis[r][c] = 1; // Set vis up here to fix this case: (Diagonal gets considered, then set as visited but the correct way to go is left then up)
        /*
        4 1
        a a b a
        b b z e
        l l s d
        k k a s
        aedsakklbaab
        */

        if (cur_ind[r][c] == s.size() - 1) return true;

        vector<pii> adj;

        if (r + 1 <= n && a[r + 1][c] == s[cur_ind[r][c] + 1]) adj.eb(r + 1, c);
        if (r - 1 >= 1 && a[r - 1][c] == s[cur_ind[r][c] + 1]) adj.eb(r - 1, c);
        if (c + 1 <= n && a[r][c + 1] == s[cur_ind[r][c] + 1]) adj.eb(r, c + 1);
        if (c - 1 >= 1 && a[r][c - 1] == s[cur_ind[r][c] + 1]) adj.eb(r, c - 1);
        if (r + 1 <= n && c + 1 <= n && a[r + 1][c + 1] == s[cur_ind[r][c] + 1]) adj.eb(r + 1, c + 1);
        if (r + 1 <= n && c - 1 >= 1 && a[r + 1][c - 1] == s[cur_ind[r][c] + 1]) adj.eb(r + 1, c - 1);
        if (r - 1 >= 1 && c + 1 <= n && a[r - 1][c + 1] == s[cur_ind[r][c] + 1]) adj.eb(r - 1, c + 1);
        if (r - 1 >= 1 && c - 1 >= 1 && a[r - 1][c - 1] == s[cur_ind[r][c] + 1]) adj.eb(r - 1, c - 1);

        for (auto x : adj) {
            int nr = x.fi; int nc = x.se;
            if (!vis[nr][nc]) {
                cur_ind[nr][nc] = cur_ind[r][c] + 1;
                qu.emplace(nr, nc);
            }
        }

    }

    return false;
}


int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= q; i++) {
        string c; cin >> c;
        bool found = false;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (bfs(c, mp(j, k))) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) cout << "good puzzle!" << el;
        else cout << "bad puzzle!" << el;

    }
}