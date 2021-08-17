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

// Idea: binary search

const int MAXN = 500003;

int n, ans = INF;
ll psa[MAXN], m;

int main() {
    fastio();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a; psa[i] = psa[i - 1] + a;
    }

    for (int i = 1; i <= n; i++) {
        int ind = upper_bound(psa, psa + n + 1, psa[i] - m) - (psa) - 1;
        if (ind >= 0) {
            ans = min(ans, abs(i - ind));
        }
    }

    cout << (ans == INF ? -1 : ans) << el;
}
