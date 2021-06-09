#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
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

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>

#define sei set<int>
#define sepi set<pair<int, int>>

#define mii unordered_map<int, int>

using namespace std;


//---------------End of template-------------------------------

const int MM = 3002;

int r, s, min_diff = MM;
mii m;
mii g;
sepi am;
char a[MM][MM];



int main() {

    fastio();

    cin >> r >> s;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= s; j++) {
            char b;
            cin >> b;
            a[i][j] = b;
            if (b == 'X') {
                m[j] = i;
                am.emplace(i, j);
            }
            else if (b == '#') {
                if (!g.contains(j)) g[j] = i;
            }
        }
    }

    for (auto const& [j, i] : m) {
        min_diff = min(min_diff, g[j] - i);
    }
    min_diff--;

    for (auto &x : am) {
        int i = x.fi; int j = x.se;
        if (am.contains(mp(i - min_diff, j))) a[i + min_diff][j] = 'X';
        else {
            a[i][j] = '.';
            a[i + min_diff][j] = 'X';
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= s; j++) {
            cout << a[i][j];
        }
        cout << el;
    }

}