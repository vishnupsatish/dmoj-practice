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

const int MAX_N = 102;
const int MAX_X = 10002;

int x, n, dp[MAX_X];

int main() {
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int j = v; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - v] + 1);
        }
    }

    cout << dp[x] << el;

}
