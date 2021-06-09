#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>

using namespace std;


//---------------End of template-------------------------------

int n;
ll ans, a[10000], x;

int main() {

    fastio();

    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(begin(a), a + n, greater<>());

    for (int i = 0; i < n; i++) {

        if (i == n - 1) {
            if (a[i] <= x) {
                ans += a[i];
                break;
            }
            if (x == 1) {
                ans += a[i] - x + 1;
                break;
            }
            ans += (long long)((long double)(a[i] + max(0ll, a[i] - x + 1)) / (long double)(2) * (long double)(min(x, a[i])));
            break;
        }

        if (a[i] - a[i + 1] + 1 <= x) {
            ans += (long long)(((long double)(a[i] + a[i + 1]) / (long double)(2)) * (long double)(a[i] - a[i + 1] + 1));
            x -= a[i] - a[i + 1] + 1;
        }
        else {
            ans += (long long)(((long double)(a[i] + (a[i] - x + 1)) / (long double)(2)) * (long double)(x));
            x = 0;
        }

        if (x == 0) break;
    }

    cout << ans << el;

}