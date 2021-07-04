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

const int MAXN = 750005;

int t, n;
string a;
int rpsa[MAXN], wpsa[MAXN], minwr[MAXN];

int main() {
    fastio();

    cin >> t;

    while (t--) {
        memset(rpsa, 0, sizeof(rpsa));
        memset(wpsa, 0, sizeof(wpsa));
        memset(minwr, INF, sizeof(minwr));

        cin >> n >> a;

        int ans = INF;

        for (int i = 0; i < n; i++) {
            rpsa[i + 1] = rpsa[i] + (a[i] == 'R');
            wpsa[i + 1] = wpsa[i] + (a[i] == 'W');
        }

        for (int i = 1; i <= n; i++) {
            minwr[i] = min(minwr[i - 1], wpsa[i] - rpsa[i]); // We rearrange the equation from (wpsa[n] - wpsa[j]) + (rpsa[j] - rpsa[i]) + wpsa[i] to
                                                            // (wpsa[n] - wpsa[j]) + (rpsa[j]) + (wpsa[i] - rpsa[i]) and precalculate the best wpsa[i] - rpsa[i] up to a right index value
        }

        for (int j = 2; j < n; j++) {
            ans = min(ans, (wpsa[n] - wpsa[j]) + rpsa[j] + (minwr[j - 1])); // We do j - 1 because the first 'R' prefix cannot be exactly positioned at the beginning of the 'R' suffix, thereby removing any 'W's
        } // We rearrange this equation

        cout << ans << el;
    }
}

