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

// Idea: monostack store index, and ans is subtract index when it becomes greater than current element

const int MAXN = 1e6 + 3;

int n, h[MAXN];
vi ms;

int main() {
    fastio();

    cin >> n;

    for (int i = 0; i < n; i++) cin >> h[i];

    for (int i = 0; i < n; i++) {
        while (!ms.empty() && h[i] >= h[ms.back()]) ms.pop_back();
        if (ms.empty()) cout << i << ' ';
        else cout << i - ms.back() << ' ';
        ms.eb(i);
    }
}
