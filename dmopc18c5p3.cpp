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

const int MAXN = 2e5 + 3;

int n, ans;
ll m, psa[MAXN];

int main() {
    fastio();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        psa[i] = psa[i - 1] + a;
    }

    for (int i = 1; i <= n; i++) {
        int ind = upper_bound(begin(psa), begin(psa) + n, psa[i] - m) - psa;
        ans = max(ans, i - ind);
    }

    cout << ans << el;
}

