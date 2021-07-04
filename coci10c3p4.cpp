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
#define ld long double
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

// Idea: create the string of letters that appear in each column, then remove them one-by-one and add them to a set, if the
// set has less elements then the number of columns, then one or more strings are repeated, so break


const int MAXRC = 1e3 + 3;

int r, c, ans;
string a[MAXRC];

int main() {
    fastio();

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char b; cin >> b;
            a[j] = b + a[j];
        }
    }

    for (int i = 1; i < c; i++) {
        uset<string> uni;

        for (int j = 1; j <= c; j++) {
            a[j].pop_back();
            uni.emplace(a[j]);
        }

        if (uni.size() != c) break;

        ans++;
    }

    cout << ans << el;
}
