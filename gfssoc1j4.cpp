#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pii pair<int, int>
#define fi first
#define se second
#define pll pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>

#define pb push_back
#define eb emplace_back

#define dq deque

#define uset unordered_set

#define umap unordered_map


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXN = 4;

char a[MAXN][MAXN];
bool o, x;

bool o_won() {
    if (a[1][1] == 'O' && a[1][2] == 'O' && a[1][3] == 'O') return true;
    if (a[2][1] == 'O' && a[2][2] == 'O' && a[2][3] == 'O') return true;
    if (a[3][1] == 'O' && a[3][2] == 'O' && a[3][3] == 'O') return true;
    if (a[1][1] == 'O' && a[2][1] == 'O' && a[3][1] == 'O') return true;
    if (a[1][2] == 'O' && a[2][2] == 'O' && a[3][2] == 'O') return true;
    if (a[1][3] == 'O' && a[2][3] == 'O' && a[3][3] == 'O') return true;
    if (a[1][1] == 'O' && a[2][2] == 'O' && a[3][3] == 'O') return true;
    if (a[1][1] == 'O' && a[2][2] == 'O' && a[3][3] == 'O') return true;
    if (a[1][3] == 'O' && a[2][2] == 'O' && a[3][1] == 'O') return true;
    return false;
}

bool x_won() {
    if (a[1][1] == 'X' && a[1][2] == 'X' && a[1][3] == 'X') return true;
    if (a[2][1] == 'X' && a[2][2] == 'X' && a[2][3] == 'X') return true;
    if (a[3][1] == 'X' && a[3][2] == 'X' && a[3][3] == 'X') return true;
    if (a[1][1] == 'X' && a[2][1] == 'X' && a[3][1] == 'X') return true;
    if (a[1][2] == 'X' && a[2][2] == 'X' && a[3][2] == 'X') return true;
    if (a[1][3] == 'X' && a[2][3] == 'X' && a[3][3] == 'X') return true;
    if (a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X') return true;
    if (a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X') return true;
    if (a[1][3] == 'X' && a[2][2] == 'X' && a[3][1] == 'X') return true;
    return false;
}


int main() {
    fastio();

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }

    x = x_won();
    o = o_won();

    if (x && o) cout << "Error, redo" << el;
    else if (x) cout << "Timothy" << el;
    else if (o) cout << "Griffy" << el;
    else cout << "Tie" << el;
}