#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+3;

int n, e, num_nodes[MAXN];
double d[MAXN], old_d[MAXN];
vector<tuple<int, double, double>> adj[MAXN];

// SPFA + track number of nodes

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        int u, v; double de, s; cin >> u >> v >> de >> s;
        adj[u].emplace_back(v, de, s);
        adj[v].emplace_back(u, de, s);
    }

    deque<int> q;

    q.push_front(1);

    for (int i = 2; i <= n; i++) {
        d[i] = 1e9;
    }

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto x: adj[u]) {
            int v = get<0>(x); double de = get<1>(x), s = get<2>(x);
            if (d[v] == d[u] + de/(s*(double)0.75)*(double)60 && num_nodes[v] > num_nodes[u] + 1) {
                num_nodes[v] = num_nodes[u] + 1;
                if (find(q.begin(), q.end(), v) == q.end()) {
                    q.push_back(v);
                }
            }
            else if (d[v] > d[u] + de/(s*(double)0.75)*(double)60) {
                d[v] = d[u] + de/(s*(double)0.75)*(double)60;
                old_d[v] = old_d[u] + de/s*(double)60;
                num_nodes[v] = num_nodes[u] + 1;
                if (find(q.begin(), q.end(), v) == q.end()) {
                    q.push_back(v);
                }
            }
        }
    }

    cout << num_nodes[n] << '\n' << round(d[n] - old_d[n]) << '\n';
}
