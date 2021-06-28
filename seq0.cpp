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

#define str string

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

const int MAXN = 1e6 + 3;

int n;
ll a[MAXN], dp[MAXN];

int main() {
    cin >> n;

    if (n == 0) { cout << 0 << el; return 0; }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1] = a[1] < 0 ? 0 : a[1];

    for (int i = 2; i <= n; i++) {
        if (a[i] < 0) dp[i] = dp[i - 1];
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }

    cout << dp[n] << el;

}
