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

// Idea: 2D PSA to determine which are 100% before and 100% after, then the unknown is the people in the one before, one after quadrants

const int MAXA = 653;
const int MAXN = 5e5 + 3;

int n, psa[MAXA][MAXA], a[MAXN], b[MAXN], max_score = 651;

int main() {
    fastio();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i]; a[i]++; b[i]++; psa[a[i]][b[i]]++;
    }

    for (int i = 1; i <= max_score; i++) {
        for (int j = 1; j <= max_score; j++) {
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        int best = psa[max_score][max_score] - psa[max_score][b[i]] - psa[a[i]][max_score] + psa[a[i]][b[i]] + 1;
        int worst = psa[a[i] - 1][b[i] - 1];
        if (a[i] == max_score) worst += psa[1][b[i]] - psa[1][b[i] - 1]; // If a[i] is 650, then find the number that are 0 and have same a[i], meaning this will always be better than them.
        if (b[i] == max_score) worst += psa[a[i]][1] - psa[a[i] - 1][1];
        cout << best << ' ' << n - worst << el;
    }
}
