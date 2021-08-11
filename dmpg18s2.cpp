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

// O(n^2) for subtask 2 (lol I need to think for a full solution I am dumb)

const int MAXN = 200003;

int n;
ll a[MAXN], psa[MAXN];

int main() {
    fastio();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i]; psa[i] = psa[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        for (int j = i; j <= n; j++) {
            ans += psa[j] - psa[j - i];
        }
        cout << ans << el;
    }

//    1 1 1 1 1
//    1 2 3 4 5
//
//    5
//    8
//    9
//    8
//    5
}