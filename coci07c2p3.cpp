#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
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
#include <unordered_set>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>
#define si stack<int>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>
#define dqll deque<long long>

#define sei unordered_set<int>
#define sepi unordered_set<pair<int, int>>

#define mii map<int, int>
#define mpii map<int, pair<int, int>>

using namespace std;

//---------------End of template-------------------------------

const int MM = 21;

int r, c;
char a[MM][MM];
str cu;
str ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";



str mins(const str &s1, const str &s2) {
    if (s1 > s2) return s2;
    else return s1;
}



int main() {

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];

            if (a[i][j] == '#') {
                if (cu.length() > 1) ans = mins(cu, ans);
                cu = "";
                continue;
            }

            cu += a[i][j];

            if (j == c) {
                if (cu.length() > 1) ans = mins(cu, ans);
                cu = "";
            }
        }
    }

    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {

            if (a[j][i] == '#') {
                if (cu.length() > 1) ans = mins(cu, ans);
                cu = "";
                continue;
            }

            cu += a[j][i];

            if (j == r) {
                if (cu.length() > 1) ans = mins(cu, ans);
                cu = "";
            }
        }
    }

    cout << ans << el;



}
