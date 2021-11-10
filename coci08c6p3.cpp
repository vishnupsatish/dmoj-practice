#include <bits/stdc++.h>

using namespace std;

// Idea: use 2D PSA to query number of cubes in a rectangle, 
// get all pairs of factors of the number of cubes such that a 
// rectangle will be formed, then find all rectangles, and add
// the number of squares in the current rectangle where there
// is more than one cube stacked on top of each other

const int MAXN = 103;

int n, m, a[MAXN][MAXN], psa[MAXN][MAXN], bad[MAXN][MAXN], ans = 1e5;
set<pair<int, int>> rect;

int get_cubes(int r1, int c1, int r2, int c2) { // r1, c1 is top-left, r2, c2 is bottom-right
    return psa[r2][c2] - psa[r2][c1 - 1] - psa[r1 - 1][c2] + psa[r1 - 1][c1 - 1];
}

int get_bad(int r1, int c1, int r2, int c2) { // r1, c1 is top-left, r2, c2 is bottom-right
    return bad[r2][c2] - bad[r2][c1 - 1] - bad[r1 - 1][c2] + bad[r1 - 1][c1 - 1];
}


int main() {
    cin >> n >> m; 
    
    for (int i = 1; i <= m; i++) {
        int r, c; cin >> r >> c;
        a[r][c]++;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + a[i][j];
            bad[i][j] = bad[i - 1][j] + bad[i][j - 1] - bad[i - 1][j - 1] + max(0, a[i][j] - 1);
        }
    }
    
    for (int i = 1; i <= sqrt(m) + 1; i++) {
        if (m % i == 0 && i <= n && m / i <= n) {
            rect.emplace(i, m / i);
            rect.emplace(m / i, i);
        }
    }
    
    for (auto [r, c]: rect) {
        for (int i = 1; i + r - 1 <= n; i++) {
            for (int j = 1; j + c - 1 <= n; j++) {
                ans = min(ans, m - get_cubes(i, j, i + r - 1, j + c - 1) + get_bad(i, j, i + r - 1, j + c - 1));
            }
        }
    }
    
    cout << ans << '\n';
}
