/**
*  author:  vishnus
*  created: 2023-02-10
*  editorial: true
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/06qzO40

const int mb = 30;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> psa(n + 1, vector<int>(mb));
  auto RangeOne = [&](int L, int R, int bit) {
    return psa[R + 1][bit] - psa[L][bit];
  };
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < mb; j++) {
      psa[i + 1][j] = psa[i][j] + ((a[i] >> j) & 1);
    }
  }
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(mb, -1)));
  function<int(int, int, int)> Solve = [&](int L, int R, int bit) -> int {
    int &cur = dp[L][R][bit];
    if (cur != -1) {
      return cur;
    }
    if (bit == 0) {
      cur = min(RangeOne(L, R, bit), R - L + 1 - RangeOne(L, R, bit));
      for (int i = L; i < R; i++) {
        cur = min(cur, RangeOne(L, i, bit) + R - i - RangeOne(i + 1, R, bit));
      }
      return cur;
    }
    cur = min(RangeOne(L, R, bit), R - L + 1 - RangeOne(L, R, bit)) + Solve(L, R, bit - 1);
    for (int i = L; i < R; i++) {
      cur = min(cur, RangeOne(L, i, bit) + R - i - RangeOne(i + 1, R, bit) + Solve(L, i, bit - 1) + Solve(i + 1, R, bit - 1));
    }
    return cur;
  };
  cout << Solve(0, n - 1, mb - 1) << '\n';
}
