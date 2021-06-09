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
#define si stack<int>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>
#define dqll deque<long long>

#define sei set<int>
#define sepi set<pair<int, int>>

#define mii unordered_map<int, int>

using namespace std;


//---------------End of template-------------------------------

const int MM = 1e5 + 2;

int n, m, t, low[MM], dfn[MM], parent[MM], vis[MM];
vi adj[MM];
sei art;

void dfs(int u) {
    dfn[u] = low[u] = ++t;
    vis[u] = 1;
    int c = 0;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u] && parent[u] != -1) art.insert(u);
            c++;
        } else if (v != parent[u]) {
            low[u] = min(low[u], dfn[v]); // Why dfn[v]? Because low is for DIRECT ANCESTORS while low[v] may hold it for a descendant of v that is not an ancestor of u
        }
    }
    if (parent[u] == -1 && c > 1) art.insert(u);
}

int main() {

    fastio();

    memset(parent, -1, sizeof(parent));

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].eb(y);
        adj[y].eb(x);
    }

    for (int i = 1; i <= n; i++) dfs(i);

    cout << art.size() << el;
    for (auto x : art) cout << x << el;

}