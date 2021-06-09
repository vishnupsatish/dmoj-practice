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

using namespace std;


//---------------End of template-------------------------------

const int NN = 100002;

int n, m, k, rem = 0, dsu[NN];
sei uni;


int find(int e) {
    if (e != dsu[e]) {
        dsu[e] = find(dsu[e]);
    }
    return dsu[e];
}



int main() {

    fastio();

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) dsu[i] = i;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v)) {
            rem += 1;
        }
        dsu[find(u)] = find(v);
    }

    for (int i = 1; i <= n; i++) uni.insert(find(i));

    int connected_c = uni.size();

    cout << max(0, connected_c  - 1 - min(k, rem)) << el;

}