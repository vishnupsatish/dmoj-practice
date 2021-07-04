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

// Idea: use DSU to store groups, then model adjacent friends using
// an array with index being friend from, value being friend to

// Another way to do would be not use DSU but instead just run a for
// loop and check if cur node != start, check https://dmoj.ca/submission/3701266

const int MAXN = 1e4 + 5;

int n, dsu[MAXN], adj[MAXN];


int find(int e) {
    if (dsu[e] != e) dsu[e] = find(dsu[e]);
    return dsu[e];
}


void merge(int u, int v) {
    dsu[find(u)] = find(v);
}

int main() {
    fastio();

    cin >> n;
    for (int i = 1; i < MAXN; i++) dsu[i] = i;

    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        adj[u] = v; merge(u, v);
    }

    while (true) {
        int u, v; cin >> u >> v;
        if (!u) break;
        if (find(u) != find(v)) cout << "No" << el;
        else {
            int ans = 0;
            int cur = u;
            while (adj[cur] != v) {
                cur = adj[cur]; ans++;
            }
            cout << "Yes " << ans << el;
        }
    }
}
