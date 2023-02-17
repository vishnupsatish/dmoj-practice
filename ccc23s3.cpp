#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, r, c;
  cin >> n >> m >> r >> c;


  auto Odd = [&](int num) {
    return num & 1;
  };
  int swp = false;

  if (((r != n && c != m) || (r == n && c == m)) && (r != 0 && c != 0)) {
    vector<vector<char>> a(n, vector<char>(m, '0'));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = 'a';
      }
    }
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < n; j++) {
        a[j][i] = 'a';
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '0') {
          a[i][j] = 'b';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }





  else if (r == n || c == m) {
    if (c == m) {
      swap(r, c);
      swap(n, m);
      swp = true;
    }
    vector<vector<char>> a(n, vector<char>(m, '0'));
    if (Odd(m) == 0 && Odd(c) != 0) {
      cout << "IMPOSSIBLE" << '\n';
      return 0;
    }
    if (Odd(m) == 0) {
      for (int i = 0; i < c / 2; i++) {
        a[0][i] = 'b';
        a[n - 1][i] = 'b';
      }
      for (int i = m - 1; i > (m - 1 - c / 2); i--) {
        a[0][i] = 'b';
        a[n - 1][i] = 'b';
      }
    }

    if (Odd(m) == 1) {
      for (int i = 0; i < c / 2; i++) {
        a[0][i] = 'b';
        a[n - 1][i] = 'b';
      }
      for (int i = m - 1; i > (m - 1 - c / 2); i--) {
        a[0][i] = 'b';
        a[n - 1][i] = 'b';
      }
      if (Odd(c) == 1) {
        a[0][m / 2] = 'b';
        a[n - 1][m / 2] = 'b';
      }
    }

    for (int i = 1; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = 'a';
      }
    }
    for (int i = 0; i < m; i++) {
      if (a[0][i] == '0') {
        a[0][i] = 'a';
        a[n - 1][i] = 'd';
      }
    }

    // deal with swap
    if (!swp) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << a[i][j];
        }
        cout << '\n';
      }
    } else {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cout << a[j][i];
        }
        cout << '\n';
      }
    }
  }





  else if ((r == 0 || c == 0) && !(r == 0 && c == 0)) {
    if (r == 0) {
      swap(r, c);
      swap(n, m);
      swp = true;
    }
    vector<vector<char>> a(n, vector<char>(m, '0'));
    if (r != n) {
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = 'a';
        }
      }
      vector<int> chs = {'b', 'c', 'd', 'e', 'f'};
      for (int i = r; i < n; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = chs[j % 5];
        }
      }
    }
    if (r == n) {
      for (int i = 0; i < m; i++) {
        a[0][i] = 'a';
      }
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = 'b';
        }
      }
    }
    if (!swp) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << a[i][j];
        }
        cout << '\n';
      }
    } else {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cout << a[j][i];
        }
        cout << '\n';
      }
    }
  }


  
  

  else if (r == 0 && c == 0) {
//    cout << 'h';
    vector<vector<char>> a(n, vector<char>(m, '0'));
    vector<int> chs = {'b', 'c', 'd', 'e', 'f'};
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = chs[j % 5];
      }
    }
    for (int i = 0; i < m - 1; i++) {
      a[n - 1][i] = 'a';
    }
    char which = 'a';
    for (; which <= 'z'; which++) {
      if (which != a[n - 1][m - 2] && which != a[n - 2][m - 1]) {
        break;
      }
    }
    a[n - 1][m - 1] = which;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }

}
