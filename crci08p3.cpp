#include <bits/stdc++.h>

using namespace std;

// Idea: for each empty cell, check the below conditions where gas can flow (if it's up, down, left, right for example, then output +)
// |: up, down
// -: left, right
// +: up, down, left, right
// 1: down, right
// 2: up, right
// 3: up, left
// 4: down, left

const int MAXN = 27;

int n, m;
char a[MAXN][MAXN];


// Does gas come in from the left to r, c?
bool l(int r, int c) {
    c--;
    return a[r][c] == '-' || a[r][c] == '1' || a[r][c] == '+' || a[r][c] == '2';
}


// Does gas come in from the right to r, c?
bool r(int r, int c) {
    c++;
    return a[r][c] == '-' || a[r][c] == '3' || a[r][c] == '+' || a[r][c] == '4';
}


// Does gas come in from the top to r, c?
bool u(int r, int c) {
    r--;
    return a[r][c] == '|' || a[r][c] == '1' || a[r][c] == '+' || a[r][c] == '4';
}


// Does gas come in from the bottom to r, c?
bool d(int r, int c) {
    r++;
    return a[r][c] == '|' || a[r][c] == '2' || a[r][c] == '+' || a[r][c] == '3';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != '.') continue;

            // Does gas come from all four directions? Then it has to be a '+'
            if (d(i, j) && u(i, j) && l(i, j) && r(i, j)) {
                cout << i << ' ' << j << ' ' << '+' << '\n';
                return 0;
            } else if (d(i, j) && u(i, j)) {
                cout << i << ' ' << j << ' ' << '|' << '\n';
                return 0;
            } else if (l(i, j) && r(i, j)) {
                cout << i << ' ' << j << ' ' << '-' << '\n';
                return 0;
            } else if (d(i, j) && l(i, j)) {
                cout << i << ' ' << j << ' ' << '4' << '\n';
                return 0;
            } else if (l(i, j) && u(i, j)) {
                cout << i << ' ' << j << ' ' << '3' << '\n';
                return 0;
            } else if (u(i, j) && r(i, j)) {
                cout << i << ' ' << j << ' ' << '2' << '\n';
                return 0;
            } else if (r(i, j) && d(i, j)) {
                cout << i << ' ' << j << ' ' << '1' << '\n';
                return 0;
            }
        }
    }
}
