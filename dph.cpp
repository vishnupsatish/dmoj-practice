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

const int MAXN = 1e3 + 3;

int h, w, dp[MAXN][MAXN];
char a[MAXN][MAXN];

int main() {
    fastio();

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) cin >> a[i][j];
    }

    dp[1][1] = 1;

    for (int i = 2; i <= w; i++) {
        if (a[1][i] == '#') dp[1][i] = 0;
        else dp[1][i] = dp[1][i - 1];
    }

    for (int i = 2; i <= h; i++) {
        if (a[i][1] == '#') dp[i][1] = 0;
        else dp[i][1] = dp[i - 1][1];
    }

    for (int i = 2; i <= h; i++) {
        for (int j = 2; j <= w; j++) {
            if (a[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[h][w] << el;
}
