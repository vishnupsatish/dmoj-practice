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

// Idea: Run topo sort, and if the number of elems in the finished topo
// sort is equal to the number of nodes, then it is a DAG, else, NO

const int MAXN = 1e3 + 3;

int n, ind[MAXN], topo_number;
vi adj[MAXN];
queue<int> q;

int main() {
    fastio();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a; cin >> a;
            if (a) {
                adj[i].eb(j);
                ind[j] += 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.emplace(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo_number++;
        for (int v : adj[u]) {
            ind[v]--;
            if (!ind[v]) q.emplace(v);
        }
    }

    if (topo_number != n) cout << "NO" << el;
    else cout << "YES" << el;
}