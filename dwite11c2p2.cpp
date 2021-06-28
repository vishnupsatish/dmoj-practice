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

const int MAXN = 12;

int h, w, cur_ind, t = 5;
char ans[MAXN][MAXN], a[MAXN][MAXN];
string s;

void solve() {
    memset(a, 0, sizeof(a));
    memset(ans, 0, sizeof(ans));

    cur_ind = 0;
    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    cin >> s;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == s[cur_ind] && cur_ind <= s.size()) {
                cur_ind++;
                ans[i][j] = '.';
            } else {
                ans[i][j] = '#';
            }
        }
    }


    if (cur_ind != s.size()) {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= h; j++) {
                cout << 'x';
            }
            cout << el;
        }
    } else {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cout << ans[i][j];
            }
            cout << el;
        }
    }

}

int main() {
    for (int i = 1; i <= 5; i++) solve();
}
