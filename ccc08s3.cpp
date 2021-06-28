#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pll pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>

#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque

#define uset unordered_set

#define umap unordered_map


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXRC = 22;

int r, c, t, vis[MAXRC][MAXRC], dist[MAXRC][MAXRC];
char a[MAXRC][MAXRC];
deque<pi> q;
vector<pi> adj;

void get_adj(int cr, int cc) {
    if (a[cr][cc] == '+') {
        if (a[cr + 1][cc] != 0 && a[cr + 1][cc] != '*') adj.eb(cr + 1, cc);
        if (a[cr - 1][cc] != 0 && a[cr - 1][cc] != '*') adj.eb(cr - 1, cc);
        if (a[cr][cc + 1] != 0 && a[cr][cc + 1] != '*') adj.eb(cr, cc + 1);
        if (a[cr][cc - 1] != 0 && a[cr][cc - 1] != '*') adj.eb(cr, cc - 1);
    }
    else if (a[cr][cc] == '-') {
        if (a[cr][cc + 1] != 0 && a[cr][cc + 1] != '*') adj.eb(cr, cc + 1);
        if (a[cr][cc - 1] != 0 && a[cr][cc - 1] != '*') adj.eb(cr, cc - 1);
    }
    else if (a[cr][cc] == '|') {
        if (a[cr + 1][cc] != 0 && a[cr + 1][cc] != '*') adj.eb(cr + 1, cc);
        if (a[cr - 1][cc] != 0 && a[cr - 1][cc] != '*') adj.eb(cr - 1, cc);
    }
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    q.clear();
    q.eb(1, 1);
    vis[1][1] = 1;
    dist[1][1] = 1;

    while (!q.empty()) {
        int cr = q.front().fi, cc = q.front().se; q.pop_front();
        if (cr == r && cc == c) return dist[cr][cc];
        adj.clear();
        get_adj(cr, cc);
        for (auto v : adj) {
            int nr = v.fi, nc = v.se;
            if (!vis[nr][nc]) {
                vis[nr][nc] = 1;
                q.eb(nr, nc);
                dist[nr][nc] = dist[cr][cc] + 1;
            }
        }
    }
    return -1;

}


int main() {
    cin >> t;

    while (t--) {
        memset(a, 0, sizeof(a));
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
            }
        }
        cout << bfs() << el;
    }



}
