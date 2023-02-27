#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ppv(n), pv(n), v(n);
  vector<int> ans(n, 1e9);
  ans[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    pv[i] = abs(a[i] - a[i + 1]);
    ans[1] = min(ans[1], abs(a[i] - a[i + 1]));
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      v[i] = ppv[i + 1] + abs(a[i] - a[i + len - 1]);
      ans[len - 1] = min(ans[len - 1], v[i]);
    }
    swap(ppv, pv);
    swap(v, pv);
    for (int i = 0; i < n; i++) {
      v[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
