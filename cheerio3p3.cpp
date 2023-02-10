/**
*  author:  vishnus
*  created: 2023-02-09
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/vfQXrkL

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int k = (int) round((sqrt(2 * n + 1) - 1) / 2);
  vector<int> ans;
  for (int i = 1; i <= k; i++) {
    ans.push_back(i);
  }
  int v = 2 * k + 1;
  int cur = v;
  ans.push_back(cur);
  while (cur <= n) {
    cur += v;
    if (cur <= n) {
      ans.push_back(cur);
    } else if ((cur > n && (2 * cur - v) / 2 < n)) {
      ans.push_back((cur - v + n) / 2);
    }
  }
  int lgh = (int) ans.size();
  cout << lgh << '\n';
  for (int i = 0; i < lgh; i++) {
    cout << ans[i] << (i == lgh - 1 ? '\n' : ' ');
  }
}
