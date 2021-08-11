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

// Idea: LOL this is just a pattern I observed. I will think of proof later. LOL.

ll n, m;
int k;
map<ll, int> r_sum;
map<ll, int> c_sum;

vector<ll> r_sum_odd;
vector<ll> c_sum_odd;


void solve() {
    cin >> n >> m >> k;
    while (k--) {
        ll a, b; cin >> a >> b;
        if (!r_sum.contains(a)) r_sum.insert({a, 1});
        else r_sum[a]++;
        if (!c_sum.contains(b)) c_sum.insert({b, 1});
        else c_sum[b]++;
    }

    int rans = 0;
    int cans = 0;

    for (auto [k, v] : r_sum) {
        if (v % 2 == 1) {
            rans++;
            r_sum_odd.eb(k);
        }
    }

    for (auto [k, v] : c_sum) {
        if (v % 2 == 1) {
            cans++;
            c_sum_odd.eb(k);
        }
    }

    cout << max(rans, cans) << el;


    int cur_r = 0;
    for (auto c : c_sum_odd) {
        if (cur_r == r_sum_odd.size()) {
            cout << n << ' ' << c << el;
        } else {
            cout << r_sum_odd[cur_r] << ' ' << c << el;
            cur_r++;
        }
    }

    while (cur_r != r_sum_odd.size()) {
        cout << r_sum_odd[cur_r] << ' ' << m << el;
        cur_r++;
    }
}


int main() {
    fastio();
    int T = 1;
//    cin >> T;
    while (T--) solve();
}
