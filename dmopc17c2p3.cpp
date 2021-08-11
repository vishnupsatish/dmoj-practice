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

const int MAXN = 200003;

int n, r, x, y, rabbit[MAXN];
vi adj[MAXN];


pii dfs(int u, int parent) {
    int ret = rabbit[u] ? 0 : INF; // Base case: when the current node has a bad rabbit
    bool on_path_to_dest = false; // Determines if the current node is on the path from x to y

    if (u == y) on_path_to_dest = true;

    for (auto v : adj[u]) {
        if (v == parent) continue; // Do not go back to parent
        pii nxt = dfs(v, u); // Go to the neighbour
        if (nxt.se) ret = min(ret, nxt.fi); // If the current node is on the path to y, then take the min of its distance to rabbit and the current min distance.
                                            // We DO NOT add 1 since the min distance will be the same as the neighbour's, since the neighbour is part of the path
                                            // to y and we want to get the min path out of all of the nodes on the path to the rabbit that the neighbour is acquainted with

        else ret = min(ret, nxt.fi + 1); // If the current node is NOT on the path to y, then add one to its distance to the rabbit since we WILL NOT be using the
                                         // neighbour node and the rabbit's distance should be the closest distance to the CURRENT NODE, not the NEIGHBOUR'S PATH
        on_path_to_dest |= nxt.se; // If any of the neighbouring nodes are on a path to y, then the current node will be too
    }

    return mp(ret, on_path_to_dest);
}


int main() {
    fastio();

    cin >> n >> r;

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }

    for (int i = 1; i <= r; i++) {
        int rab; cin >> rab; rabbit[rab] = 1;
    }

    cin >> x >> y;

    cout << dfs(x, 0).fi << el;
}
