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
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

int n, ans;
vector<pair<int, int>> letters;

int main() {
    fastio();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char k; cin >> k;
            if (k != '.') {
                letters.emplace_back(i, j);
            }
        }
    }

    int ls = letters.size();

    for (int i = 0; i < ls; i++) {
        ld y_1 = letters[i].fi, x_1 = letters[i].se;
        for (int j = i + 1; j < ls; j++) {
            ld y_2 = letters[j].fi, x_2 = letters[j].se;
            for (int k = j + 1; k < ls; k++) {
                ld y_3 = letters[k].fi, x_3 = letters[k].se;
                if ((y_2 - y_1) / (x_2 - x_1) == (y_3 - y_2) / (x_3 - x_2)) ans++;
            }
        }
    }

    cout << ans << el;
}
