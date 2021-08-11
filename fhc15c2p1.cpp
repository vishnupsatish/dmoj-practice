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


// Idea: use Deque, and try adding from end, and from beginning, then see if it works.

int t, n;


bool f(dq<int> a, bool f) {
    dq<int> dest;
    if (f) {
        dest.eb(a.front()); a.pop_front();
    } else {
        dest.eb(a.back()); a.pop_back();
    }
    while (!a.empty()) {
        if (a.front() == dest.front() - 1) {
            dest.push_front(a.front()); a.pop_front();
        } else if (a.front() == dest.back() + 1) {
            dest.eb(a.front()); a.pop_front();
        } else if (a.back() == dest.front() - 1) {
            dest.push_front(a.back()); a.pop_back();
        } else if (a.back() == dest.back() + 1) {
            dest.eb(a.back()); a.pop_back();
        } else return false;
    }
    return true;
}


void solve() {
    cin >> t;
    for (int c = 1; c <= t; c++) {
        dq<int> a;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int e; cin >> e; a.eb(e);
        }
        if (f(a, 0) || f(a, 1)) cout << "Case #" << c << ": yes" << el;
        else cout << "Case #" << c << ": no" << el;
    }
}


int main() {
    fastio();
    int T = 1;
//    cin >> T;
    while (T--) solve();
}
