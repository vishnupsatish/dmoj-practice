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

// Idea: put Euclidean distance in array, sort, binary search (or you can use a PSA as well, set psa[ceil(euclidean distance)] and do psa

const int MAXN = 186750;

int n, q;
ld a[MAXN];

int main() {
    fastio();

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        ld x, y; cin >> x >> y;
        a[i] = sqrt(x * x + y * y);
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= q; i++) {
        int r; cin >> r;

        int ind = upper_bound(a + 1, a + n + 1, r) - a - 1;
        cout << ind << el;
    }
}
