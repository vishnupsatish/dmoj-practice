#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque<int>

#define uset unordered_set


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------

const int MM = 2e5 + 3;

int n, m, ans = 1e9;
ll k, d[MM];

int main() {
    fastio();

    cin >> n >> m >> k;
    d[1] = m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        d[a] -= 1;
        d[b + 1] += 1;
    }

    for (int i = 1; i <= n; i++) { // Difference array
        d[i] += d[i - 1];
    }

    for (int i = 1; i <= n; i++) { // Convert to PSA
        d[i] += d[i - 1];
    }

    for (int i = 1; i <= n; i++) { // BS to find least-length contiguous subarray that sums to k (n log n)
        if (d[i] < k) continue;
        int ind = upper_bound(begin(d), begin(d) + n + 1, d[i] - k) - d - 1;
        ans = min(ans, abs(ind - i));
    }

    cout << (ans == 1000000000 ? -1 : ans) << el;

}
