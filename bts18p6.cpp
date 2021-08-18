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
#define fi first
#define se second
#define el "\n"
#define ll long long
#define ld long double
#define vi vector<int>
#define eb emplace_back
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

// Idea: https://imgur.com/gallery/tTcv67j (nice problem)

const int MAXT = 1e5 + 3;

int n, t;
ll dif[3][MAXT];

int main() {
    fastio();

    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        ll l, r, a, b, c; cin >> l >> r >> a >> b >> c;
        dif[0][l] += a;
        dif[1][l] += b - 2ll * a * l;
        dif[2][l] += a * l * l - b * l + c;

        dif[0][r + 1] -= a;
        dif[1][r + 1] -= b - 2ll * a * l;
        dif[2][r + 1] -= a * l * l - b * l + c;
    }

    for (ll i = 1; i <= t; i++) {
        for (int j = 0; j < 3; j++) {
            dif[j][i] += dif[j][i - 1];
        }

        cout << i * i * dif[0][i] + i * dif[1][i] + dif[2][i] << (i != t ? " " : el);
    }
}
