#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
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
#include <unordered_set>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque<int>

#define uset unordered_set


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------

const int MM = 1e5 + 2;

int t, n, x[MM], y[MM];
map<int, int> first_occurrence_reverse_x;

int main() {
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        first_occurrence_reverse_x.clear();
        cin >> n;
        for (int i = n - 1; i >= 0; i--) {
            cin >> x[i];
            if (!first_occurrence_reverse_x.contains(x[i])) first_occurrence_reverse_x[x[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int ind = upper_bound(x, x + n, y[i]) - x - 1;
            if (ind >= n) continue;

            ans = max(ans, i - ((n - 1) - first_occurrence_reverse_x[x[ind]]));
        }
        cout << "The maximum distance is " << ans << el;

    }
}
