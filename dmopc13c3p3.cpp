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

#define str string

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

const int MAXN = 1503;

int n, h, a[MAXN][MAXN], vis[MAXN][MAXN];
queue<pii> q;

bool bfs() {
    q.emplace(1, 1);

    while (!q.empty()) {
        int r = q.front().fi, c = q.front().se; q.pop();

        if (r == n && c == n) return true;

        if (r + 1 <= n && abs(a[r + 1][c] - a[r][c]) <= h && !vis[r + 1][c]) {
            vis[r + 1][c] = 1; q.emplace(r + 1, c);
        }
        if (r - 1 > 1 && abs(a[r - 1][c] - a[r][c]) <= h && !vis[r - 1][c]) {
            vis[r - 1][c] = 1; q.emplace(r - 1, c);
        }
        if (c + 1 <= n && abs(a[r][c + 1] - a[r][c]) <= h && !vis[r][c + 1]) {
            vis[r][c + 1] = 1; q.emplace(r, c + 1);
        }
        if (c - 1 > 1 && abs(a[r][c - 1] - a[r][c]) <= h && !vis[r][c - 1]) {
            vis[r][c - 1] = 1; q.emplace(r, c - 1);
        }

    }

    return false;

}

int main() {

    fastio();

    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << (bfs() ? "yes" : "no") << el;

}
