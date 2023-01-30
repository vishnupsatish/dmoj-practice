/**
*  author:  vishnus
*  created: 2023-01-30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n, 0); // 1 if gone 0 if stay
  a[0] = a[1] = 1;
  for (int i = 4; i < n; i += 4) {
    a[i] = 1;
    if (i != n - 1) {
      a[i + 1] = 1;
    }
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    m += !a[i];
  }
  cout << m << '\n';
  for (int i = 0; i < n; i++) {
    cout << (a[i] ? "_" : "M");
  }
  cout << '\n';
}
