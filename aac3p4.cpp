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

const int MAXNM = 5e5 + 3;

int n, m, ans;
umap<ll, int> rs, cs;

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int curr; cin >> curr;
        if (curr != -1) rs[curr - i]++;
    }
    for (int i = 1; i <= m; i++) {
        int curc; cin >> curc;
        if (curc != -1) cs[curc - i]++;
    }

    for (auto [x, v] : rs) {
        for (int i = 0; i < v; i++) {
            if (cs.contains(x) && cs[x]) {
                ans++;
                cs[x]--;
            }
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
