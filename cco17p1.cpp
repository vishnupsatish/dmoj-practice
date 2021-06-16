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

int k, v, pre = 0;

vi s;

int cal(int n) {
    return n * ((double)(n) / (double)(2) + 0.5);
}

int bs(int n) { // Binary search for the not greatest point such that those many nodes can form an SCC
    int l = 0;
    int r = min(n, 5000);

    while (l < r) {
        int mid = (l + r) / 2;
        if (cal(mid) > n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (cal(l) == n) {
        return l;
    }
    return l - 1;

}


int main() {

    cin >> k;

    while (k != 0) {
        int a = bs(k);
        s.eb(a + 1);
        k -= cal(a);
        v += a + 1;
    }

    cout << v << " " << v + s.size() - 1 << el;

    for (auto e : s) {
        for (int i = pre + 1; i < e + pre; i++) cout << i << " " << i + 1 << el;
        cout << e + pre << " " << pre + 1 << el;

        if (pre != 0) {
            cout << pre - e + 1 << " " << e + pre << el;
        }

        pre += e;
    }

}
