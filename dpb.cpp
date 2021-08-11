#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
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
#endif

#define fastio() cin.tie(0);ios::sync_with_stdio(0);
#define fi first
#define se second
#define el "\n"
#define ll long long
#define ld long double
#define vi vector<int>
#define eb emplace_back
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXN = 1e5 + 3;

int n, k, a[MAXN], dp[MAXN];

int main() {
    fastio();

    memset(dp, INF, sizeof(dp));

    cin >> n >> k;

    cin >> a[1];
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        cin >> a[i];

        for (int j = i - 1; j >= max(1, i - k); j--) {
            dp[i] = min(dp[j] + abs(a[i] - a[j]), dp[i]);
        }

    }

    cout << dp[n] << el;
}
