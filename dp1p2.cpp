#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>


using namespace std;

int n;
int dp[1002][1002];
int psa[1002];


int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i]; psa[i] = dp[i][i] + psa[i - 1];
    }

    for (int len=1; len<n; len++) {
        for (int L=1; L+len <= n; L++) {
            int R = L + len;
            dp[L][R] = psa[R] - psa[L - 1] - min(dp[L + 1][R], dp[L][R - 1]);
        }
    }

    int p1 = dp[1][n];
    cout << p1 << "\n";

    return 0;
}