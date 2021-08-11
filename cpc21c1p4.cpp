#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
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
#endif

#define fastio() cin.tie(0);ios::sync_with_stdio(0);
#define fi first
#define se second
#define el "\n"
#define ll long long
#define ld long double
#define vi vector<int>
#define eb emplace_back
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

// Idea: make a reverse graph, and if a node does not have a max value reachable from it, DFS from it,
// sending its value (greedily choosing the node with largest value) then for every adj node forever,
// set its max val to the val passed on originally. Do this until all nodes visited, then go reverse
// (since we need to maximize x) and find its max value, if max value is not itself, then break

const int MAXN = 3e5 + 3;

int n, m, mx[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int val) {
    mx[u] = val;
    for (int v : adj[u]) {
        if (mx[v] == 0) dfs(v, val);
    }
}

int main() {
    fastio();

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[v].eb(u);
    }

    for (int i = n; i >= 1; i--) {
        if (mx[i] == 0) dfs(i, i);
    }

    for (int i = n; i >= 1; i--) {
        if (mx[i] > i) {
            cout << i << ' ' << mx[i] << el; return 0;
        }
    }

    cout << -1 << el;
}