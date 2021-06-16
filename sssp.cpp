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

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>
#define si stack<int>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>
#define dqll deque<long long>

#define sei unordered_set<int>
#define sepi unordered_set<pair<int, int>>

#define mii map<int, int>
#define mpii map<int, pair<int, int>>

using namespace std;

//---------------End of template-------------------------------

const int MM = 1001;

int n, m, p[MM];
vpi adj[MM];
pq<pi> q;

int main() {

    cin >> n >> m;

    for (int i = 2; i <= n; i++) p[i] = 1e9;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].eb(u, w);
        adj[u].eb(v, w);

    }

    q.emplace(0, 1);

    while (!q.empty()) {
        int dist = q.top().fi, u = q.top().se; q.pop();
        for (auto al : adj[u]) {
            int v = al.fi, w = al.se;

            if (dist + w < p[v]) {
                p[v] = dist + w;
                q.emplace(p[v], v);
            }

        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (p[i] == 1e9 ? -1 : p[i]) << el;
    }



}
