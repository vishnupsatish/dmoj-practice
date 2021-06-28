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

int t, n, x, y, z;
set<tuple<int, int, int>> ans;

int main() {
    fastio();

    cin >> t;

    while (t--) {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> z;
            int gc_d = gcd(gcd(abs(x), abs(y)), abs(z));
            x /= gc_d; y /= gc_d; z /= gc_d;
            ans.insert(mt(x, y, z));
        }

        cout << ans.size() << el;
    }
}
