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

// Idea: use two pointers. Since the number of distinct elements are monotonically increasing as
// the right pointer moves right, then all to the right works, and move left pointer.

const int MAXN = 1e6 + 3;

int n, k, dist, a[MAXN], freq[MAXN];
ll ans;

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int l = 0, r = 0; r < n; r++) {
        freq[a[r]]++;
        if (freq[a[r]] == 1) dist++;
        while (dist >= k) {
            ans += n - r;
            freq[a[l]]--;
            if (freq[a[l]] == 0) dist--;
            l++;
        }
    }

    cout << ans << el;

}


int main() {
    fastio();
    int T = 1;
//    cin >> T;
    while (T--) solve();
}
