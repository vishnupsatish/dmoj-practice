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

// PSA of 2x graph, then do sliding window min for the min psa[l - 1] to subtract with

const int MAXN = 1e5 + 3;

int n, k;
ll ans, psa[2 * MAXN];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        ll cur; cin >> cur;
        psa[i] = psa[i + n] = cur;
    }

    deque<int> q;

    q.eb(0);

    for (int i = 1; i <= 2 * n; i++) {
        psa[i] += psa[i - 1];
        while (!q.empty() && psa[q.back()] > psa[i]) q.pop_back();
        q.eb(i);
        while (!q.empty() && q.front() < i - k) q.pop_front();
        ans = max(ans, psa[i] - psa[q.front()]);
    }

    cout << ans << el;

}
