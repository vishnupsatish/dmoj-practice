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

const int MAXRC = 28;

int f, r, c, vis[MAXRC][MAXRC];
char a[MAXRC][MAXRC];
vi rooms;


int bfs(pii start) {
    int ans = 0;
    queue<pii> q;
    q.emplace(start);
    vis[start.fi][start.se] = 1;

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        ans++;
        int cr = u.fi, cc = u.se;
        if (cr + 1 <= r && a[cr + 1][cc] != 'I' && !vis[cr + 1][cc]) {
            q.emplace(cr + 1, cc);
            vis[cr + 1][cc] = 1;
        }
        if (cr - 1 >= 1 && a[cr - 1][cc] != 'I' && !vis[cr - 1][cc]) {
            q.emplace(cr - 1, cc);
            vis[cr - 1][cc] = 1;
        }
        if (cc + 1 <= c && a[cr][cc + 1] != 'I' && !vis[cr][cc + 1]) {
            q.emplace(cr, cc + 1);
            vis[cr][cc + 1] = 1;
        }
        if (cc - 1 >= 1 && a[cr][cc - 1] != 'I' && !vis[cr][cc - 1]) {
            q.emplace(cr, cc - 1);
            vis[cr][cc - 1] = 1;
        }
    }

    return ans;
}


int main() {
    fastio();

    cin >> f >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (!vis[i][j] && a[i][j] != 'I') {
                rooms.eb(bfs(mp(i, j)));
            }
        }
    }

    sort(rooms.begin(), rooms.end(), greater());

    int su = 0;
    int no = 0;

    for (auto x : rooms) {
        if (su + x > f) break;
        su += x;
        no++;
    }

    string room_spelling = "rooms";
    if (no == 1) room_spelling = "room";

    cout << no << " " << room_spelling << ", " << f - su << " square metre(s) left over" << el;
}
