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

const int MM = 1e5 + 2;

int n, a[MM][4], dp[MM][16];


int solve(int now, int mask) {
    if (dp[now][mask] != -1) return dp[now][mask];
    if (now > n - 1) return 0;
    if (mask >= 16) return 0;

    int ret = solve(now + 1, mask); // Try skipping and not choosing current item

    for (int gr = 0; gr < 4; gr++) { // Try choosing current item for each grade
        if ((mask & 1 << gr) != 0) continue;
        if (a[now][gr] != -1) ret = max(ret, solve(now + 1, mask | 1 << gr) + a[now][gr]); // Recurse
    }


    return dp[now][mask] = ret;
}


int main() {

    fastio();

    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve(0, 0) << el;
}