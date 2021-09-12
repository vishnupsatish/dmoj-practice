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

int n;
vi a, b, moves;

signed main() {
    fastio();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        a.emplace_back(c);
        og.emplace_back(c);
    }

    reverse(a.begin(), a.end());

    b.emplace_back(a.back());

    a.pop_back();

    moves.emplace_back(1);

    while (!a.empty()) {
        int cur = a.back();
        int hm = 0;
        for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] >= cur) break;
            hm++;
        }
        if (hm != 0) {
            a.insert(a.end(), b.end() - hm, b.end());
            for (int i = 0; i < hm; i++) {
                b.pop_back();
            }
           moves.emplace_back(-hm);
        }

        b.insert(b.end(), a.end() - hm - 1, a.end());
        for (int i = 0; i <= hm; i++) a.pop_back();

        moves.emplace_back(hm + 1);
    }
    moves.emplace_back(-n);

    cout << moves.size() << el;

    for (auto m : moves) cout << m << el;
}
