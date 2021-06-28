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


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXN = 2002;
const int MAXK = 202;

int n, m, k, a, b, ans = INF - 5, dist[MAXN][MAXK];
vector<tuple<int, int, int>> adj[MAXN];
deque<int> q;


int main() {

    cin >> k >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, t, h; cin >> a >> b >> t >> h;
        adj[a].eb(b, t, h);
        adj[b].eb(a, t, h);
    }

    cin >> a >> b;

    memset(dist, INF, sizeof(dist));

    memset(dist[a], 0, sizeof(dist[a]));

    q.eb(a);

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto all : adj[u]) {
            bool putin = false;
            int v = get<0>(all), w = get<1>(all), hull = get<2>(all);
            for (int i = hull; i < k; i++) {
                int nd = dist[u][i - hull] + w;
                if (nd < dist[v][i]) {
                    dist[v][i] = nd; putin = true;
                }

            }
            if (putin && find(q.begin(), q.end(), v) == q.end()) q.eb(v);
        }
    }

    for (int i = 0; i <= k; i++) {
        ans = min(ans, dist[b][i]);
    }
    cout << (ans != INF - 5 ? ans : -1) << el;

}