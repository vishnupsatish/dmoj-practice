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

const int MM = 1e6 + 2;

int n, opt;
ll ls, ts, rs;
dqll a;

//---------------End of template-------------------------------


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        ts += l;
        a.eb(l);
    }

    for (int i = 0; i < n - 1; i++) {
        ls += a[i];
        opt = i;
        if (abs(ls - (ts - ls)) <= abs((ls + a[i + 1]) - (ts - (ls + a[i + 1])))) break;

    }

    cout << abs(ls - (ts - ls)) << " ";

    for (int te = 1; te < n; te++) {

        a.eb(a.front());
        a.pop_front();


        if (opt == 0) {
            opt = n - 2;
            ll temp = ls;
            ls = ts - (ts - ls);
            rs = temp;
        } else {
            opt -= 1;
            ls -= a.back();
        }

        ls -= a[opt];

        for (int i = opt; i < n - 1; i++) {
            ls += a[i];
            opt = i;
            if (abs(ls - (ts - ls)) <= abs((ls + a[i + 1]) - (ts - (ls + a[i + 1])))) break;
        }

        if (te != n - 1) cout << abs(ls - (ts - ls)) << " ";
        else cout << abs(ls - (ts - ls)) << el;

    }

}