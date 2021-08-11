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
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define el "\n"
#define pq priority_queue
#define ll long long
#define ld long double
#define ull unsigned long long
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

const int MAXNM = 503;

int n, m, a[MAXNM][MAXNM], dp[MAXNM][MAXNM];


void solve(int case_number) {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (i == 1) dp[i][j] = dp[i][j - 1] + a[i][j];
            else if (j == 1) dp[i][j] = dp[i - 1][j] + a[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    cout << dp[n][m] << el;
}


signed main() {
    fastio();
    int T = 1;
//    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
}
