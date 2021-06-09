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

const int MM = 1e4 + 2;

int n, vis[MM];
vi adj[MM];

pi bfs(int sta) {

    qpi q;
    q.emplace(sta, 0);
    vis[sta] = 1;

    while (!q.empty()) {

        int u = q.front().fi; int lvl = q.front().se;
        q.pop();

        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.emplace(v, lvl + 1);
                vis[v] = 1;
            }
        }

        if (q.empty()) {
            return mp(u, lvl);
        }
    }
}


int main() {

    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].eb(y);
        adj[y].eb(x);
    }

    pi f = bfs(1);
    int ns = f.fi;

    memset(vis, 0, sizeof(vis));

    cout << bfs(ns).se << el;

}
