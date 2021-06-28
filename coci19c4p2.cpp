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

const int MAXN = 3e5 + 3;
const int MAXH = 1e6 + 3;

int n, k, maxval, a[MAXN], ans[MAXH];
umap<int, int> cnt;
vi s;


int main() {
    fastio();

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[a[i]] = 0;
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++) maxval = max(maxval, a[i]);

    for (auto [h, c] : cnt) {

        ans[h] -= k == 0; // If k is 0, we don't want to include the same element as h/h will always be 0

        if (h > k) { // A remainder cannot be greater than the divisor, so we do this (e.g. 12/3 can't have a remainder of 4)
            for (int i = 0; i * h + k <= maxval; i += 1) { // We must start at 0
                ans[i * h + k] += c;
            }
        }

    }

    for (int i = 1; i <= n; i++) {
        cout << ans[a[i]] << (i != n ? " " : el);
    }
}