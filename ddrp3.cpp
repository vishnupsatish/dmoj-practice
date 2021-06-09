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

const int MM = 1e6 + 2;

int n, m, s, e, vis[MM];
vi adj[MM];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    cin >> s >> e;

    qpi q;
    q.emplace(s, 0);

    while (!q.empty()) {
        int u = q.front().fi;
        int lvl = q.front().se;
        q.pop();
        if (u == e) {
            cout << m - lvl << el;
            break;
        }
        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.emplace(v, lvl + 1);
                vis[v] = 1;
            }
        }
    }


}