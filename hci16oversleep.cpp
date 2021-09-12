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
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXN = 1003;

int n, m, dist[MAXN][MAXN], vis[MAXN][MAXN];
char a[MAXN][MAXN];
pair<int, int> s = {0, 0};
pair<int, int> e = {0, 0};


int main() {
    fastio();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 's') s = {i, j};
            else if (a[i][j] == 'e') e = {i, j};
        }
    }

    if (s.fi == 0 || e.fi == 0) {
        cout << -1 << el; return 0;
    }

    queue<pair<int, int>> q;

    q.emplace(s);
    vis[s.fi][s.se] = 1;

    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        if (u == e) {
            cout << dist[u.fi][u.se] - 1 << el;
            return 0;
        }
        int un = u.fi; int um = u.se;
        if (un + 1 <= n && !vis[un + 1][um] && a[un + 1][um] != 'X') {
            dist[un + 1][um] = dist[un][um] + 1;
            q.emplace(un + 1, um);
            vis[un + 1][um] = 1;
        }
        if (un - 1 >= 1 && !vis[un - 1][um] && a[un - 1][um] != 'X') {
            dist[un - 1][um] = dist[un][um] + 1;
            q.emplace(un - 1, um);
            vis[un - 1][um] = 1;
        }
        if (um + 1 <= m && !vis[un][um + 1] && a[un][um + 1] != 'X') {
            dist[un][um + 1] = dist[un][um] + 1;
            q.emplace(un, um + 1);
            vis[un][um + 1] = 1;
        }
        if (um - 1 >= 1 && !vis[un][um - 1] && a[un][um - 1] != 'X') {
            dist[un][um - 1] = dist[un][um] + 1;
            q.emplace(un, um - 1);
            vis[un][um - 1] = 1;
        }
    }

    cout << -1 << el;
}
