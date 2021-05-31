#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>

// I am lazy. Sorry. I have 256 MB anyways ¯\_(ツ)_/¯
#define int long long


#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>


using namespace std;

const int MM = 200002;

int n; int a[MM], s[MM], dsu[MM];

int find(int e) {
    if (e != dsu[e]) dsu[e] = find(dsu[e]);
    return dsu[e];
}

bool swap(int k) {
    for (int i = 1; i <= n; i++) dsu[i] = i;

    for (int i = 2; i <= n; i++) {
        if (s[i] - s[i - 1] <= k) dsu[find(i - 1)] = find(i);
    }

    for (int i = 1; i <= n; i++) {
        int new_ind = lower_bound(s, s + n + 1, a[i]) - s;
        if (find(i) != find(new_ind)) return false;
    }

    return true;
}

signed main() {

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; s[i] = a[i]; }

    sort(begin(s) + 1, s + n + 1);

    int l = 0, r = 1e18 + 2;

    while (l < r) {
        int mid = (r + l) / 2;
        if (swap(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << el;

    return 0;

}
