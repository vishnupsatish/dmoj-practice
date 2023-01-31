/**
*  author:  vishnus
*  created: 2023-01-31
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if every node in a component is in the set, then ans++ since we have to involve some second 
// component and join them. Now, when does the answer get reduced? Take a single component as an example.
// Treat it as a digraph with index 'u' pointing to value 'v'. Then, it becomes strongly connected. 
// If we have a node 'v' in the set such that 'u', that point to 'v', is not in the set, then we can 
// break the cycle and point 'v' back towards 'u'. If we have another node in the cycle that follows 
// that criteria, then we can do the same for that node and thereby increase the number of connected 
// components by 1. So if we have 4 nodes that follow that criteria, we can increase the number of 
// connected components by 3. 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<int> adj(n); // Reverse digraph; adj[i] points to i basically
  for (int i = 0; i < n; i++) {
    adj[a[i]] = i;
  }
  vector<int> dsu(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
  }
  function<int(int)> Find = [&](int e) {
    if (dsu[e] == e) {
      return e;
    }
    return dsu[e] = Find(dsu[e]);
  };
  unordered_map<int, int> cc;
  for (int i = 0; i < n; i++) {
    dsu[Find(i)] = Find(a[i]);
  }
  for (int i = 0; i < n; i++) {
    cc[Find(i)]++;
  }
  while (q--) {
    int ans = (int) cc.size();
    int ls;
    cin >> ls;
    unordered_set<int> all_s;
    unordered_map<int, unordered_set<int>> s; // maps find value to set of values in that component
    for (int i = 0; i < ls; i++) {
      int val;
      cin >> val;
      --val;
      all_s.insert(val);
      s[Find(val)].insert(val);
    }
    for (auto [fd, st] : s) {
      if ((int) st.size() == cc[fd]) {
        ans--;
        continue;
      }
      int cnt_good = 0;
      for (auto e : st) {
        if (!all_s.contains(adj[e])) {
          cnt_good++;
        }
      }
      ans += max(0, cnt_good - 1);
    }
    cout << ans << '\n';
  }
}
