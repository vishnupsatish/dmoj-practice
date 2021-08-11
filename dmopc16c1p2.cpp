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
#define pll pair<long long, long long>
#define mp make_pair
#define el "\n"
#define pq priority_queue
#define ll long long
#define ld long double
#define ull unsigned long long
#define mt make_tuple
#define vi vector<int> lol
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

// Idea: Get all lines with defined slope, count pairs

int n;
umap<int, int> a;
set<pair<int, int>> slope_intercept;
ll ans;


void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int m, b; cin >> m >> b;
		if (slope_intercept.contains(mp(m, b))) {
			cout << "Infinity" << el;
			return;
		}
		slope_intercept.emplace(m, b);
		a[m]++;
	}

	for (auto [k, v] : a) {
		ans += (n - v) * v;
	}

	cout << ans/2;
}


int main() {
	fastio();
	int T = 1;
//    cin >> T;
	while (T--) solve();
}
