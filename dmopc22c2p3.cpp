/**
*  author:  vishnus
*  created: 2023-02-03
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: let's consider the relative positions of pairs of values that don't have a GCD of
// 0. If we have something like ..2, 3, 4,.. the 2 and 4 can never go past each other and
// become something like a 4,..,2. To maintain this relative ordering, we create a graph
// (specifically, a DAG). For GCD ≠ 0, there must be a common prime factor. To optimize the
// graph creation, have a set of all primes and the indices that have that number as a prime
// factor. Then, connect these edges, and run a greedy topological sort using a priority
// queue to get the best lexicographical values for each position.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> loc(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    loc[a[i]] = i;
  }
  vector<vector<int>> adj(n + 1);
  vector<int> indeg(n + 1);
  vector<int> spf(n + 1);
  for (int i = 0; i <= n; i++) {
    spf[i] = i;
  }
  for (int p = 2; p * p <= n; p++) {
    if (spf[p] == p) {
      for (int i = p * p; i <= n; i += p) {
        if (spf[i] == i) {
          spf[i] = p;
        }
      }
    }
  }
  vector<vector<int>> nf(n + 1); // index whose value contains the i'th prime factor
  for (int i = 0; i < n; i++) {
    int cur = a[i];
    unordered_set<int> done;
    while (cur != 1) {
      if (!done.contains(spf[cur])) {
        nf[spf[cur]].push_back(i);
        done.insert(spf[cur]);
      }
      cur /= spf[cur];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < (int) nf[i].size(); j++) {
      adj[a[nf[i][j - 1]]].push_back(a[nf[i][j]]);
      indeg[a[nf[i][j]]]++;
    }
  }
  priority_queue<int> vals;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      vals.push(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    int cur = vals.top();
    vals.pop();
    cout << cur;
    for (auto v : adj[cur]) {
      indeg[v]--;
      if (indeg[v] == 0) {
        vals.push(v);
      }
    }
  }
  cout << '\n';
}
