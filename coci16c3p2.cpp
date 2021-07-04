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

// Idea: Keep a set of all elements at the current level, and then filter that set to only contain the smallest chars,
// then keep a "nxt" set which contains all of the "best" adjacent nodes from the current level set, and repeat

const int MAXN = 2e3 + 3;

int n, m;
char a[MAXN][MAXN];
set<pii> cur, nxt, tmp;


char min_char(char u, char v) {
    if (u > v) return v; return u;
}


char min_char_set() {
    char ans = 'z';
    for (auto x : cur) {
        ans = min_char(ans, a[x.fi][x.se]);
    }
    return ans;
}


int main() {
    fastio();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }

    cur.emplace(1, 1);

    for (int i = 1; i <= m + n - 1; i++) {
        nxt.clear(); tmp = cur;

        char min_char = min_char_set();
        for (auto x : tmp) {
            if (a[x.fi][x.se] != min_char) cur.erase(x);
        }

        for (auto x : cur) {
            int r = x.fi, c = x.se;
            if (r == n) nxt.emplace(r, c + 1);
            else if (c == m) nxt.emplace(r + 1, c);
            else {
                if (a[r + 1][c] == a[r][c + 1]) {
                    nxt.emplace(r + 1, c); nxt.emplace(r, c + 1);
                } else if (a[r + 1][c] < a[r][c + 1]) nxt.emplace(r + 1, c);
                else nxt.emplace(r, c + 1);
            }
        }

        for (auto x : cur) {
            cout << a[x.fi][x.se]; break;
        }

        cur = nxt;
    }

    cout << el;
}