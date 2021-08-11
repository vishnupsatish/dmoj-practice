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

int n, c[6];
set<pair<vector<int>, int>> a; // Second number is smallest number, first set is the abs value of the differences between the numbers


void solve(int case_number) {
    cin >> n;
    while (n--) {
        int min_num = INF;
        vector<int> cur;
        for (int j = 0; j < 6; j++) {
            cin >> c[j];
        }

        for (int j = 0; j < 6; j++) {
            cur.eb(abs(c[j] - c[(j + 1) % 6]));
            min_num = min(min_num, c[j]);
        }
        sort(cur.begin(), cur.end());

        if (a.contains(mp(cur, min_num))) {
            cout << "Twin snowflakes found." << el;
            return;
        }
        a.insert(mp(cur, min_num));

    }
    cout << "No two snowflakes are alike." << el;
}


signed main() {
    fastio();
    int T = 1;
//    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
}
