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

// Idea: Sieve

const int MAXM = 3163;

int n, m, primes[MAXM + 3];

int main() {
    fastio();

    memset(primes, -1, sizeof(primes));
    primes[0] = 0; primes[1] = 0;

    for (int i = 2; i <= MAXM; i++) {
        if (primes[i]) {
            for (int j = 2; j * i <= MAXM; i++) primes[i * j] = 0;
        }
    }

    cin >> n;

    while (n--) {
        cin >> m;
        vi ans;

        for (int i = 2; i <= sqrt(m) + 2; i++) {
            if (m == 1) break;
            if (!primes[i]) continue;
            while (m % i == 0 && m != 1) {
                m /= i;
                ans.eb(i);
            }
        }

        if (m != 1) ans.eb(m);

        for (auto x : ans) cout << x << ' ';
        cout << el;
    }
}
