#include <bits/stdc++.h>

using namespace std;

// Idea: for each minute, calculate the board based on the
// flooding that will occur, then run a BFS to find the answer (two BFSs)

const int MAXN = 53;

int r, c, ans[MAXN][MAXN];
char a[303][MAXN][MAXN]; // a is [minute][row][column] and represents the flood
pair<int, int> s, e;


void flood() {
    queue<tuple<int, int, int>> q; // Row, column, minute

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[0][i][j] == '*') {
                q.emplace(i, j, 0);
            }
        }
    }

    while (!q.empty()) {
        int cr = get<0>(q.front()), cc = get<1>(q.front()), min = get<2>(q.front());
        q.pop();

        for (int i = min; i <= 300; i++) a[i][cr][cc] = '*';

        if (cr < r && a[min][cr + 1][cc] != 'X' && a[min][cr + 1][cc] != 'D' && a[min][cr + 1][cc] != 'S' && a[min][cr + 1][cc] != '*' && a[min + 1][cr + 1][cc] != '*') {
            q.emplace(cr + 1, cc, min + 1);
            a[min + 1][cr + 1][cc] = '*';
        }
        if (cc < c && a[min][cr][cc + 1] != 'X' && a[min][cr][cc + 1] != 'D' && a[min][cr][cc + 1] != 'S' && a[min][cr][cc + 1] != '*' && a[min + 1][cr][cc + 1] != '*') {
            q.emplace(cr, cc + 1, min + 1);
            a[min + 1][cr][cc + 1] = '*';
        }
        if (cr > 1 && a[min][cr - 1][cc] != 'X' && a[min][cr - 1][cc] != 'D' && a[min][cr - 1][cc] != 'S' && a[min][cr - 1][cc] != '*' && a[min + 1][cr - 1][cc] != '*') {
            q.emplace(cr - 1, cc, min + 1);
            a[min + 1][cr - 1][cc] = '*';
        }
        if (cc > 1 && a[min][cr][cc - 1] != 'X' && a[min][cr][cc - 1] != 'D' && a[min][cr][cc - 1] != 'S' && a[min][cr][cc - 1] != '*' && a[min + 1][cr][cc - 1] != '*') {
            q.emplace(cr, cc - 1, min + 1);
            a[min + 1][cr][cc - 1] = '*';
        }
    }
}


string solve() {
    queue<tuple<int, int, int>> q; // Row, column, minute

    q.emplace(s.first, s.second, 0);

    ans[s.first][s.second] = 1;

    while (!q.empty()) {
        int cr = get<0>(q.front()), cc = get<1>(q.front()), min = get<2>(q.front());
        q.pop();

        if (cr == e.first && cc == e.second) return to_string(ans[cr][cc] - 1);

        if (cr < r && a[min][cr + 1][cc] != 'X' && a[min][cr + 1][cc] != 'S' && a[min][cr + 1][cc] != '*' && a[min + 1][cr + 1][cc] != '*' && ans[cr + 1][cc] == 0) {
            q.emplace(cr + 1, cc, min + 1);
            ans[cr + 1][cc] = ans[cr][cc] + 1;
        }
        if (cc < c && a[min][cr][cc + 1] != 'X' && a[min][cr][cc + 1] != 'S' && a[min][cr][cc + 1] != '*' && a[min + 1][cr][cc + 1] != '*' && ans[cr][cc + 1] == 0) {
            q.emplace(cr, cc + 1, min + 1);
            ans[cr][cc + 1] = ans[cr][cc] + 1;
        }
        if (cr > 1 && a[min][cr - 1][cc] != 'X' && a[min][cr - 1][cc] != 'S' && a[min][cr - 1][cc] != '*' && a[min + 1][cr - 1][cc] != '*' && ans[cr - 1][cc] == 0) {
            q.emplace(cr - 1, cc, min + 1);
            ans[cr - 1][cc] = ans[cr][cc] + 1;
        }
        if (cc > 1 && a[min][cr][cc - 1] != 'X' && a[min][cr][cc - 1] != 'S' && a[min][cr][cc - 1] != '*' && a[min + 1][cr][cc - 1] != '*' && ans[cr][cc - 1] == 0) {
            q.emplace(cr, cc - 1, min + 1);
            ans[cr][cc - 1] = ans[cr][cc] + 1;
        }
    }

    return "KAKTUS";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[0][i][j];
            if (a[0][i][j] == 'S') s = {i, j};
            if (a[0][i][j] == 'D') e = {i, j};
            for (int k = 1; k <= 300; k++) a[k][i][j] = a[0][i][j];
        }
    }


    flood();

    cout << solve() << '\n';
}

