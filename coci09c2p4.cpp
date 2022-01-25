#include <bits/stdc++.h>

using namespace std;

// Idea: precalculate the value to the closest tree for every point (ct).
// Then use a greedy BFS that sorts by minimum distance to a tree so far
// on a path, then when the end was found, break.

const int MAXN = 503;

int n, m, ct[MAXN][MAXN], vis[MAXN][MAXN], findvis[MAXN][MAXN];
char a[MAXN][MAXN];
pair<int, int> cur, ed;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    queue<pair<int, int>> findq;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '+') {
                findq.emplace(i, j);
                findvis[i][j] = 1;
            }
            else if (a[i][j] == 'V') cur = {i, j};
            else if (a[i][j] == 'J') ed = {i, j};
        }
    }

    while (!findq.empty()) {
        int r = findq.front().first, c = findq.front().second;
        findq.pop();

        findvis[r][c] = 1;

        if (r != n && !findvis[r + 1][c]) {
            findq.emplace(r + 1, c);
            ct[r + 1][c] = ct[r][c] + 1;
            findvis[r + 1][c] = 1;
        }
        if (c != m && !findvis[r][c + 1]) {
            findq.emplace(r, c + 1);
            ct[r][c + 1] = ct[r][c] + 1;
            findvis[r][c + 1] = 1;
        }
        if (r != 1 && !findvis[r - 1][c]) {
            findq.emplace(r - 1, c);
            ct[r - 1][c] = ct[r][c] + 1;
            findvis[r - 1][c] = 1;
        }
        if (c != 1 && !findvis[r][c - 1]) {
            findq.emplace(r, c - 1);
            ct[r][c - 1] = ct[r][c] + 1;
            findvis[r][c - 1] = 1;
        }
    }

    priority_queue<pair<int, pair<int, int>>> q; // We want a max priority queue

    q.emplace(ct[cur.first][cur.second], cur);
    vis[cur.first][cur.second] = 1;

    while (!q.empty()) {
        int dist = q.top().first, r = q.top().second.first, c = q.top().second.second;
        q.pop();

        if (make_pair(r, c) == ed) {
            cout << dist << '\n';
            break;
        }

        if (r != n && !vis[r + 1][c]) {
            vis[r + 1][c] = 1;
            q.push({min(ct[r + 1][c], dist), {r + 1, c}});
        }
        if (c != n && !vis[r][c + 1]) {
            vis[r][c + 1] = 1;
            q.push({min(ct[r][c + 1], dist), {r, c + 1}});
        }
        if (r != 1 && !vis[r - 1][c]) {
            vis[r - 1][c] = 1;
            q.push({min(ct[r - 1][c], dist), {r - 1, c}});
        }
        if (c != 1 && !vis[r][c - 1]) {
            vis[r][c - 1] = 1;
            q.push({min(ct[r][c - 1], dist), {r, c - 1}});
        }
    }
}
