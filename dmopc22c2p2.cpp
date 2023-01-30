/**
*  author:  vishnus
*  created: 2023-01-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: think of our initial array as a sorted permutation of 'n'. we can think of a line 
// between 'i' and 'i + 1' as "swapping" those indices and leaving them to be, since that's
// what it does. Answer is just the minimum number of swaps to make to get the original 
// sorted permutation, going backwards from the given array.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_set<int> s;
  for (auto &e : a) {
    cin >> e;
    --e;
    if (s.contains(e)) {
      cout << -1 << '\n';
      return 0;
    }
    s.insert(e);
  }
  int ans = 0;
  for (int val = 0; val < n; val++) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == val) {
        pos = i;
        break;
      }
    }
    if (pos == val) {
      continue;
    }
    if (pos > val) {
      while (pos != val) {
        swap(a[pos], a[pos - 1]);
        pos--;
        ans++;
      }
    } else {
      while (pos != val) {
        swap(a[pos], a[pos + 1]);
        pos++;
        ans++;
      }
    }
  }
  cout << ans << '\n';
}
