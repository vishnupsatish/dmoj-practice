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
//#define vi vector<int> lol
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

const int MAXN = 1e4 + 3;

int n, a[MAXN];


int get(int l, int r) {
    if (l != 1 && r != 1) return 1;
    if (l != 2 && r != 2) return 2;
    if (l != 3 && r != 3) return 3;
    return 4;
}


void solve() {
    cin >> n;

    string ret;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) ret += to_string(a[i]);
        else {
            int g = get(a[i - 1], a[i + 1]);
            a[i] = g;
            ret += to_string(g);
        }
    }

    cout << ret << el;
}


int main() {
    fastio();
    int T = 1;
//    cin >> T;
    while (T--) solve();
}
