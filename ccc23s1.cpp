#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> c1(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> c1[i];
    cnt += c1[i];
  }
  vector<int> c2(n);
  for (int i = 0; i < n; i++) {
    cin >> c2[i];
    cnt += c2[i];
  }
  int ans = 3 * cnt;
  for (int i = 0; i < n; i++) {
    if (c1[i] == c2[i] && c1[i] == 1 && !(i & 1)) {
      ans -= 2;
    }
    if (i < n - 1) {
      if (c1[i] == c1[i + 1] && c1[i] == 1) {
        ans -= 2;
      }
      if (c2[i] == c2[i + 1] && c2[i] == 1) {
        ans -= 2;
      }
    }
  }
  cout << ans << '\n';
}
