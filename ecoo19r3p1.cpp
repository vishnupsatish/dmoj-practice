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

// Idea: Iterate over all keys, and find all multiples of
// the key, and if the multiple exists as a key, add one

const int MAXN = 1e6 + 3;

int n, ans, maxval;
uset<int> a;

int main() {

    fastio();

    for (int _ = 1; _ <= 10; _++) {
        a.clear(); ans = 0; maxval = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int b; cin >> b; a.insert(b);
            maxval = max(maxval, b);
        }


        for (auto x : a) {
            for (int i = x * 2; i <= maxval; i += x) {
                if (a.contains(i)) ans++;
            }
        }

        cout << ans << el;

    }
}
