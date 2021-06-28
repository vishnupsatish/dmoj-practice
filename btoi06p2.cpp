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

#define str string

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

const int MAXN = 5e5 + 3;

int n, s, num;
ll k;
pii a[MAXN];

int main() { // The reasoning behind this is that if we find that when we add sum to current coin, the next coin will instead be used to make change, then don't use the current coin

    fastio();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    a[n + 1].fi = k;

    for (int i = 1; i <= n; i++) {
        if (!a[i].se && s + a[i].fi < a[i + 1].fi) {
            s += a[i].fi;
            num++;
        }
    }

    cout << num << el << k - max(s, 1) << el;

}
