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

const int MAXN = 1.5e3 + 2;

int n;
ll ans, a[MAXN];
umap<ll, int> mult;
umap<ll, int> freq;

int main() {
    fastio();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        freq[a[i]] += 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            mult[a[i] * a[j]] += 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j]) ans += ((mult[a[i] * a[j]]) - freq[a[j]] - freq[a[i]] + 3) * 4;
            else ans += ((mult[a[i] * a[j]]) - freq[a[j]] - freq[a[i]] + 1) * 4;
        }
    }

    cout << ans << el;
}