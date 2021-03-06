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

int x, n, t, f, ans;
pq<int, vector<int>, greater<int>> q; // The priority queue holds all soups that can be eaten at the current moment
vi a[MAXN];

int main() {

    fastio();

    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> f;
        a[max(0, t - x)].eb(f);
    }

    for (int i = 0; i <= MAXN; i++) { // Iterate over each time from 0 to 5e5
        for (auto r : a[i]) q.push(r); // Add the right endpoint from all intervals that start here
        while (!q.empty()) { // If we find elements that are spoiled by time i, pop them
            if (q.top() >= i) break;
            q.pop();
        }
        if (!q.empty()) { // Greedily choose one soup with the smallest right endpoint
            ans++; q.pop();
        }
    }

    cout << ans << el;

}
