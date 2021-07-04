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

// Idea: a graph is a forest if there are N nodes, M edges, and C connected components, and N - M = C.
// In this case, since there can be at most one extra edge, then N - M + 1 = C also works

const int MAXN = 2e5 + 3;

int n, m, dsu[MAXN];
uset<int> c;


int find(int e) {
    if (e != dsu[e]) dsu[e] = find(dsu[e]);
    return dsu[e];
}


int main() {
    fastio();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) dsu[i] = i;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;

        dsu[find(u)] = find(v);
    }

    for (int i = 1; i <= n; i++) {
        c.emplace(find(i));
    }

    int conn = c.size();

    cout << (n - m == conn || n - m + 1 == conn ? "YES" : "NO") << el;
}
