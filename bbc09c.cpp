#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 3;

int n, c[MAXN]; // c: 0 is pink, 1 is black
vector<int> adj[MAXN];
vector<int> ans;

// Idea: run DFS, when there are no children (or all the children have been traversed),
// check if the child is pink. If it's pink, then visit it, then the current node again
// (and change the current node), then go to the current node's parent. Then do the same
// thing recursively for every node's children.

void dfs(int u, int parent) {
    ans.push_back(u);
    for (auto v: adj[u]) {
        if (v != parent) {
            c[v] = !c[v];
            dfs(v, u);
        }
    }

    for (auto v: adj[u]) {
        if (v != parent && !c[v]){
            ans.push_back(v);
            ans.push_back(u);
            c[v] = !c[v];
            c[u] = !c[u];
        }
    }

    if (parent != -1) ans.push_back(parent);
    c[parent] = !c[parent];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] == -1) c[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    if (c[1] == 0) {
        ans.push_back(adj[1][0]);
        ans.push_back(1);
        ans.push_back(adj[1][0]);
    }

    int cnt = 1;
    for (auto x: ans) {
        cout << x << (cnt == ans.size() ? '\n' : ' ');
        cnt++;
    }
}
