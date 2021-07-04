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

const int MAXRC = 42;

int r, c, vis[MAXRC][MAXRC];
char a[MAXRC][MAXRC];
pii one, two, three, four, five;


int bfs(pii st) {
    memset(vis, 0, sizeof(vis));
    int ret = 0;

    queue<pii> q;
    q.emplace(st);

    while (!q.empty()) {
        int nr = q.front().fi, nc = q.front().se; q.pop();
        ret++;

        if (nr + 1 <= r && a[nr + 1][nc] == '.' && !vis[nr + 1][nc]) {
            q.emplace(nr + 1, nc); vis[nr + 1][nc] = 1;
        }
        if (nr - 1 >= 1 && a[nr - 1][nc] == '.' && !vis[nr - 1][nc]) {
            q.emplace(nr - 1, nc); vis[nr - 1][nc] = 1;
        }
        if (nc + 1 <= c && a[nr][nc + 1] == '.' && !vis[nr][nc + 1]) {
            q.emplace(nr, nc + 1); vis[nr][nc + 1] = 1;
        }
        if (nc - 1 >= 1 && a[nr][nc - 1] == '.' && !vis[nr][nc - 1]) {
            q.emplace(nr, nc - 1); vis[nr][nc - 1] = 1;
        }

    }
    return ret;
}


int main() {
    fastio();

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') one = mp(i, j);
            if (a[i][j] == '2') two = mp(i, j);
            if (a[i][j] == '3') three = mp(i, j);
            if (a[i][j] == '4') four = mp(i, j);
            if (a[i][j] == '5') five = mp(i, j);
        }
    }

    cout << bfs(one) << el << bfs(two) << el << bfs(three) << el << bfs(four) << el << bfs(five) << el;
}

