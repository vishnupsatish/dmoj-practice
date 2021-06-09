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

const int MM = 1e3 + 1;

int c, b, dsu[MM];
vpi edges;
sei uni;

void reset_dsu() {
    for (int i = 1; i <= c; i++) dsu[i] = i;
}

int find(int e) {
    if (e != dsu[e]) {
        dsu[e] = find(dsu[e]);
    }
    return dsu[e];
}


int main() {
    for (int _ = 0; _ < 5; _++) {
        cin >> c >> b;
        edges.clear();
        int ans = 0;

        for (int i = 0; i < b; i++) {
            int u, v;
            cin >> u >> v;
            edges.eb(u, v);
        }

        for (int i = 0; i < b; i++) {
            reset_dsu();
            uni.clear();
            for (int j = 0; j < b; j++) {
                if (j == i) continue;
                int u = edges[j].fi;
                int v = edges[j].se;
                dsu[find(u)] = find(v);

            }
            for (int j = 1; j <= c; j++) uni.insert(find(j));
            if (uni.size() != 1) ans++;
         }

        cout << ans << el;

    }
}

