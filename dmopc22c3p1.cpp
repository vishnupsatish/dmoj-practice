/**
*  author:  vishnus
*  created: 2023-01-30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n < m) {
    swap(n, m);
  }
  if (!(n * m & 1)) {
    cout << n * m / 2 << ' ' << n * m / 2 << '\n';
  } else {
    long long green = max(n * (m / 2), m * (n / 2));
    long long red = n * m - green;
    cout << red << ' ' << green << '\n';
  }
}
