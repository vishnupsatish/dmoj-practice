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

#define mii map<int, int>
#define mpii map<int, pair<int, int>>

using namespace std;

//---------------End of template-------------------------------


const int MM = 5e5 + 2;

int n, m, p[MM], mark[MM], outdeg[MM];
vi r_adj[MM];

int main() {

    fastio();

    cin >> n >> m;

    fill(begin(mark), begin(mark) + n + 1, 1);

    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        r_adj[v].eb(u);
        mark[u] = 0;
        outdeg[u] += 1; // Out-degree is the number of outgoing nodes that a node u has
    }

    qi q;

    for (int i = 1; i <= n; i++) {
        if (!outdeg[i]) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : r_adj[u]) { // Go to nodes that are adjacent to the current node; almost like a reverse BFS
            if (mark[v]) continue; // Bruh if you already visited a node why would u do it again

            if (p[v]) mark[v] = 1; // If there is a police station at the adjacent node, then police mama can force the robber to go to the current, marked node
            outdeg[v]--; // That's one less safe node that the robber can go to
            if (!outdeg[v]) mark[v] = 1; // If there are no unmarked "safe" nodes that the robber can go to, then the current node is also unsafe

            if (mark[v]) q.push(v); // Do a BFS of all of the marked nodes; think if it like plague. There's a set of rules.
                                    // If a node is adjacent to a marked node and follows the rules, then it gets the plague too
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << mark[i] << el;
            break;
        }
        cout << mark[i] << " ";
    }

}
