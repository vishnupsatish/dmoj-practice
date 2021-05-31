#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>
#include <deque>

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>

#define di deque<int>


using namespace std;

int n, ind, dfn[1002], low[1002], vis[1002];
vi adj[1002], s;

void tarjan(int u) {
    dfn[u] = low[u] = ++ind;
    s.emplace_back(u);
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (vis[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (find(s.begin(), s.end(), v) != s.end()) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size() - 1; i++) cout << s[i] << " ";
        cout << s[s.size() - 1] << el;
        s.clear();
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) adj[i].pb(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) tarjan(i);
    }

}
