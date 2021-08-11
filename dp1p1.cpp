#pragma GCC optimize("Ofast", "unroll-loops")

#include <stdio.h>
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

// Idea: DP

const int MAXN = 100003;

int n, a[MAXN], prev1, prev2, cur, tmp_prev1;

int main() {
    scanf("%d", &n);

    for (int i = 2; i <= n + 1; i++) {
        scanf("%d", &a[i]);
        cur = max(prev1, prev2 + a[i]);
        tmp_prev1 = prev1;
        prev1 = cur;
        prev2 = tmp_prev1;
    }

    printf("%d", cur);
}