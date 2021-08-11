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

// Idea: brute-force with disjoint-set, since small constraints

const int MAXN = 103;

int n, m, dsu[MAXN];
vector<pii> edges;


int find(int e) {
    if (dsu[e] != e) dsu[e] = find(dsu[e]);
    return dsu[e];
}


int main() {
    fastio();

    int T = 5;
    while (T--) {
        edges.clear();
        edges.eb(0, 0); // One-indexing

        int ans = 0;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) dsu[i] = i;

        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            edges.eb(u, v);
        }

        for (int i = 1; i <= m; i++) { // Remove edge i from graph (see if it is a bridge)
            for (int j = 1; j <= n; j++) dsu[j] = j;

            for (int j = 1; j <= m; j++) {
                if (i == j) continue; // Remove edge i
                int u = edges[j].fi; int v = edges[j].se;
                dsu[find(u)] = find(v);
            }

            for (int j = 1; j < n; j++) {
                if (find(j) != find(j + 1)) {ans++; break;}
            }
        }

        cout << ans << el;
    }
}
