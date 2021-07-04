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

// Idea: use a PSA, then check all subsequences of increasing lengths,
// and use the square root property to check if a number is prime

const int MAXN = 1e4 + 3;

int t, n, a[MAXN], psa[MAXN];


bool is_prime(int nu) {
    for (int i = 2; i * i <= nu + 1; i++) {
        if (nu % i == 0) return false;
    }
    return true;
}


int main() {
    fastio();

    cin >> t;

    while (t--) {
        memset(a, 0, sizeof(a));
        memset(psa, 0, sizeof(psa));
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i]; psa[i] = psa[i - 1] + a[i];
        }

        bool flag = false;
        for (int len = 1; len < n; len++) {
            for (int l = 1; l + len <= n; l++) {
                int r = l + len;
                if (is_prime(psa[r] - psa[l - 1])) {
                    cout << "Shortest primed subsequence is length " << len + 1 << ": ";
                    for (int i = l; i <= r; i++) cout << a[i] << ' ';
                    cout << el;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) continue;

        cout << "This sequence is anti-primed." << el;
    }
}

