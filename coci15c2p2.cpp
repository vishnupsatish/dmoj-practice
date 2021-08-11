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

const int MAXN = 22;

int n, m;
vi cant_combine[MAXN];
bool used_in_current_combination[MAXN];


int f(int cur) {
    if (cur == n + 1) return 1;

    int ans = f(cur + 1); // Try not choosing the current element and skipping to the next element

    bool can_use = true;
    for (auto e : cant_combine[cur]) {
        if (used_in_current_combination[e]) {
            can_use = false; // Determine if the current element cannot be selected if one of its "cannot be combined with" elements have been selected previously
            break;
        }
    }

    if (can_use) { // If the current element can be selected, then try selecting the next element
        used_in_current_combination[cur] = true;
        ans += f(cur + 1);
        used_in_current_combination[cur] = false;
    }

    return ans;
}


int main() {
    fastio();

    cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v;
        cant_combine[u].eb(v);
        cant_combine[v].eb(u);
    }

    cout << f(1) << el;
}
