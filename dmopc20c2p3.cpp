/**
*  author:  vishnus
*  created: 2023-02-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: say an edge exists from u -> v. If we add edge from v -> u, the new connections 
// would be (number of people that go into 'v' not through 'u') * (number of people that
// one person from 'u' would visit not through 'v')

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
  }
  vector<vector<int>> adj(n);
  vector<vector<int>> radj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
  vector<int> rx(n);
  vector<int> vis(n);
  function<int(int)> Dfs = [&](int u) -> int {
    if (vis[u]) {
      return rx[u] + a[u];
    }
    vis[u] = 1;
    for (auto v : adj[u]) {
      rx[u] += Dfs(v);
    }
    return rx[u] + a[u];
  };
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      Dfs(i);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (long long) rx[i] * a[i];
    ans += (long long) a[i] * (a[i] - 1ll);
  }
  vector<int> revvis(n);
  vector<int> revrx(n);
  function<int(int)> ReverseDfs = [&](int u) -> int {
    if (revvis[u]) {
      return revrx[u] + a[u];
    }
    revvis[u] = 1;
    for (auto v : radj[u]) {
      revrx[u] += ReverseDfs(v);
    }
    return revrx[u] + a[u];
  };
  for (int i = 0; i < n; i++) {
    if (!revvis[i]) {
      ReverseDfs(i);
    }
  }
  long long add = 0;
  for (int i = 0; i < n; i++) {
    for (auto v : adj[i]) {
      add = max(add, (long long) (a[i] + rx[i] - rx[v] - a[v]) * (long long) (revrx[v] - revrx[i] - a[i] + a[v])); // (people that go out) * (people that come in)
    }
  }
  cout << ans + add << '\n';
}
