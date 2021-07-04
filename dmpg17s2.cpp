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

const int MAXN = 1e5 + 3;

int n, q, dsu[MAXN];


int find(int e) {
    if (e != dsu[e]) dsu[e] = find(dsu[e]);
    return dsu[e];
}


int main() {
    fastio();

    cin >> n >> q;

    for (int i = 1; i <= n; i++) dsu[i] = i;

    for (int i = 1; i <= q; i++) {
        char qu; int u, v; cin >> qu >> u >> v;
        if (qu == 'A') {
            dsu[find(u)] = find(v);
        } else {
            cout << (find(u) == find(v) ? 'Y' : 'N') << el;
        }
    }
}

