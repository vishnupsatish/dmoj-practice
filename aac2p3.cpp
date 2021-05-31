#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <cstring>

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>

using namespace std;

const int M = 1502;

int n, m, psa[M][M], a[M][M];
bool vis[M][M];


bool bfs(int s) {
    memset(vis, 0, sizeof(vis));
    queue<pi > q;
    q.emplace(s, s);
    while (!q.empty()) {
        pi e = q.front();
        q.pop();
        int r = e.fi;
        int c = e.se;
        if (r == n && c == m) {
            return true;
        }
        vpi temp = {mp(r - 1, c), mp(r + 1, c), mp(r, c + 1), mp(r, c - 1)};
        for (auto &x : temp) {
            int nr = x.fi;
            int nc = x.se;
            if (nr - s + 1 < 1 || nc - s + 1 < 1 || nr > n || nc > m) continue;
            bool pos = false;
            if (nr == s) {
                pos = (psa[nr][nc] - psa[nr][nc - s] == 0);
            }
            else if (nc == s) {
                pos = (psa[nr][nc] - psa[nr - s][nc] == 0);
            } else {
                pos = (psa[nr][nc] - psa[nr - s][nc] - psa[nr][nc - s] + psa[nr - s][nc - s] == 0);
            }
            if (!vis[nr][nc] && pos) {
                vis[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }

    }
    return false;

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    char c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            a[i][j] = c == 'O' ? 0 : 1;
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + a[i][j];
        }
    }

    int l = 1;
    int r = min(n, m) + 1;

    while (l < r) {
        int mid = (l + r) / 2;
        if (psa[mid][mid] != 0) {
            r = mid;
            continue;
        }

        if (bfs(mid)) l = mid + 1;
        else r = mid;
    }

    cout << l - 1 << el;


    return 0;


}
