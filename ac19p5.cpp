#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>


using namespace std;

int dp[1501][1501], n;
ll a[1501][1501];

int f(int r, int c) {
    if (dp[r][c] != 0) return dp[r][c];

    int re = 0;
    if (a[r - 1][c] != 0 && a[r - 1][c] < a[r][c]) re = max(re, 1 + f(r - 1, c));
    if (a[r + 1][c] != 0 && a[r + 1][c] < a[r][c]) re = max(re, 1 + f(r + 1, c));
    if (a[r][c - 1] != 0 && a[r][c - 1] < a[r][c]) re = max(re, 1 + f(r, c - 1));
    if (a[r][c + 1] != 0 && a[r][c + 1] < a[r][c]) re = max(re, 1 + f(r, c + 1));

    return dp[r][c] = re;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, f(i, j));
        }
    }

    cout << ans << el;


}