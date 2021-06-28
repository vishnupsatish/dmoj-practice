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
#define pll pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>

#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque

#define uset unordered_set

#define umap unordered_map


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXF = 7;
const int MAXR = 1e4 + 2;

int f, r, q, a, b, c, psa[MAXF][MAXR];

int main() {

    fastio();

    cin >> f >> r;

    for (int i = 1; i <= f; i++) {
        for (int j = 1; j <= r; j++) {
            int d; cin >> d;
            psa[i][j] = psa[i][j - 1] + d;
        }
    }

    cin >> q;

    for (int i = 1; i <= q; i++) {
        cin >> a >> b >> c;
        cout << psa[c][b] - psa[c][a - 1] << el;
    }

}
