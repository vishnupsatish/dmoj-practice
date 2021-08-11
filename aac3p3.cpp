#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
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
#endif

#define fastio() cin.tie(0);ios::sync_with_stdio(0);
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define el "\n"
#define pq priority_queue
#define ll long long
#define ld long double
#define ull unsigned long long
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

const int MAXN = 1e6 + 3;

int n, a[MAXN], b[MAXN];

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << a[1] << el << 'E' << el;
        return;
    }

    sort(a + 1, a + n + 1);

    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            b[i] = a[l]; l++;
        }
        else {
            b[i] = a[r]; r--;
        }
    }

    for (int i = 1; i <= n; i++) cout << b[i] << (i != n ? " " : el);


    for (int i = 1; i <= n - (n % 2); i++) {
        if (i % 2) cout << 'B';
        else cout << 'S';
    }
    if (n % 2) cout << 'E' << el;
    else cout << el;
}


int main() {
    fastio();
    int T = 1;
//    cin >> T;
    while (T--) solve();
}
