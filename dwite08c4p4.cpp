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
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque<int>

#define uset unordered_set


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------

const int MM = 10;

int a[MM][MM], vis[MM][MM], dis[MM][MM];
pi st, en;
vpi adj;


void get_adj(int i, int j) {
    if (a[i + 1][j] != 1 && i + 1 <= 8) adj.eb(i + 1, j);
    if (a[i - 1][j] != 1 && i - 1 >= 1) adj.eb(i - 1, j);
    if (a[i][j + 1] != 1 && j + 1 <= 8) adj.eb(i, j + 1);
    if (a[i][j - 1] != 1 && j - 1 >= 1) adj.eb(i, j - 1);
    if (a[i + 1][j + 1] != 1 && i + 1 <= 8 && j + 1 <= 8) adj.eb(i + 1, j + 1);
    if (a[i + 1][j - 1] != 1 && i + 1 <= 8 && j - 1 >= 1) adj.eb(i + 1, j - 1);
    if (a[i - 1][j + 1] != 1 && i - 1 >= 1 && j + 1 <= 8) adj.eb(i - 1, j + 1);
    if (a[i - 1][j - 1] != 1 && i - 1 >= 1 && j - 1 >= 1) adj.eb(i - 1, j - 1);
}


void ans() {
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            char b; cin >> b;
            if (b == '.') a[i][j] = 0;
            else if (b == '#') a[i][j] = 1;
            else if (b == 'A') {
                a[i][j] = 3; st = mp(i, j);
            }
            else if (b == 'B') {
                a[i][j] = 4; en = mp(i, j);
            }
        }
    }

    queue<pi> q;

    q.emplace(st);
    vis[st.fi][st.se] = 1;

    while (!q.empty()) {
        int i = q.front().fi; int j = q.front().se;
        q.pop();
        if (mp(i, j) == en) break;
        adj.clear();
        get_adj(i, j);
        for (auto [ni, nj] : adj) {
            if (!vis[ni][nj]) {
                vis[ni][nj] = 1;
                dis[ni][nj] = dis[i][j] + 1;
                q.emplace(ni, nj);
            }
        }
    }

    adj.clear();
    cout << dis[en.fi][en.se] << el;
}


int main() {
    fastio();
    for (int i = 0; i < 5; i++) ans();
}
