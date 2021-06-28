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

// Idea: similar to CCC 2021 S2, store number of times each row and column was updated, then xor row and
// col with the number of times (i, j) was changed since (i, j) is counted twice in the row, col count

const int MAXN = 1e5 + 3;

int n, q, r[MAXN], c[MAXN];
map<pii, int> no;

int main() {

    fastio();

    cin >> n >> q;

    for (int _ = 1; _ <= q; _++) {
        int t, i, j; cin >> t >> i >> j;

        if (t == 1) {
            r[j] = !r[j]; c[i] = !c[i];
            no[mp(i, j)] = !no[mp(i, j)];
        } else {
            cout << (r[j] ^ c[i] ^ no[mp(i, j)]) << el;
        }

    }


}
