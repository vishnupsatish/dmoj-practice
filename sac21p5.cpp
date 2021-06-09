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

int n, q, dsu[MM], siz[MM];

int find(int e) {
    if (dsu[e] != e) dsu[e] = find(dsu[e]);
    return dsu[e];
}

void create() {
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        siz[i] = 1;
    }
}

void merge(int u, int v) {
    int nu = find(u); int nv = find(v);
    if (nu == nv) return;
    dsu[find(u)] = find(v);
    siz[v] += siz[u];
}


int main() {

    cin >> n >> q;

    create();

    for (int t = 0; t < q; t++) {
        int qu;
        cin >> qu;
        if (qu == 1) {
            int u, v;
            cin >> u >> v;
            merge(u, v);

        } else {
            int s;
            cin >> s;
            cout << siz[find(s)] << el;
        }
    }


}

