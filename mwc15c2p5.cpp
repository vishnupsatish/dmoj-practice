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

// Idea: difference array

const int MAXN = 1e5 + 3;
const int MAXT = 4;

int n, k, j;
ll dif[MAXT][MAXN];

int main() {
    fastio();

    cin >> n >> k >> j;

    for (int _ = 1; _ <= j; _++) {
        int xi, xf, i, t; cin >> xi >> xf >> i >> t;
        dif[t][xi] += i;
        dif[t][xf + 1] -= i;
    }

    for (int i = 1; i <= 3; i++) {
        int ans = 0;
        for (int m = 1; m <= n; m++) {
            dif[i][m] += dif[i][m - 1];
            ans += (dif[i][m] < k);
        }
        cout << ans << el;
    }
}
