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
#define si stack<int>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>
#define dqll deque<long long>

#define sei set<int>
#define sepi set<pair<int, int>>

#define mii unordered_map<int, int>

using namespace std;


//---------------End of template-------------------------------

const int MM = 1e5 + 2;
vi flips;

int n, a1[MM], a2[MM];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a1[i];
        a2[i] = a1[i];
    }


    a1[1] = !a1[1];
    a1[2] = !a1[2];
    flips.eb(1);

    for (int i = 2; i <= n; i++) {
        if (a1[i - 1]) {
            a1[i] = !a1[i];
            a1[i - 1] = !a1[i - 1];
            a1[i + 1] = !a1[i + 1];
            flips.eb(i);
        }
    }

    if (!a1[n]) {
        cout << flips.size() << el;
        for (auto f : flips) cout << f << el;
        return 0;
    }

    flips.clear();

    for (int i = 2; i <= n; i++) {
        if (a2[i - 1]) {
            a2[i] = !a2[i];
            a2[i - 1] = !a2[i - 1];
            a2[i + 1] = !a2[i + 1];
            flips.eb(i);
        }
    }

    cout << flips.size() << el;
    for (auto f : flips) cout << f << el;
    return 0;

}
