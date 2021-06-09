#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
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

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>

using namespace std;

//---------------End of template-------------------------------

int n, m, sp[1002];
vpi adj[1002];
dqi q;

// Simple SPFA

int main() {

    memset(sp, 0x3f3f, sizeof(sp));
    sp[0] = 0;
    sp[1] = 0;

    fastio();

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].eb(v, w);
    }

    q.eb(1);

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto p : adj[u]) {
            int v = p.fi; int w = p.se;
            if (sp[u] + w < sp[v]) {
                sp[v] = sp[u] + w;
                if (find(q.begin(), q.end(), v) == q.end()) q.eb(v);
            }
        }

    }

    cout << sp[n] << el;



}