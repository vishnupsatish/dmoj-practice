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

int dp[5][303][5][303];


int ans(int w1, int h1, int w2, int h2) {
    if (dp[h1][w1][h2][w2] != 0) return dp[h1][w1][h2][w2];

    if (h1 == w1 == w2 == h2 == 1) return -1;

    // option 1
    if (h1 == 2 && ans(w1, h1 - 1, w1, h1 - 1) == -1) return dp[h1][w1][h2][w2] = 1;
    if (h2 == 2 && ans(w2, h2 - 1, w2, h2 - 1) == -1) return dp[h1][w1][h2][w2] = 1;

    for (int i = 1; i < w1; i++) {
        if (ans(w1 - i, h1, i, h1) == -1) return dp[h1][w1][h2][w2] = 1;
    }

    for (int i = 1; i < w2; i++) {
        if (ans(w2 - i, h2, i, h2) == -1) return dp[h1][w1][h2][w2] = 1;
    }

    // option 2
    if (h1 == 2 && ans(w1, 1, w2, h2) == -1) return dp[h1][w1][h2][w2] = 1;
    if (h2 == 2 && ans(w2, 1, w1, h1) == -1) return dp[h1][w1][h2][w2] = 1;

    for (int i = 1; i < min(11, w1); i++) {
        if (ans(w1 - i, h1, w2, h2) == -1) return dp[h1][w1][h2][w2] = 1;
    }

    for (int i = 1; i < min(11, w2); i++) {
        if (ans(w2 - i, h2, w1, h1) == -1) return dp[h1][w1][h2][w2] = 1;
    }

    return dp[h1][w1][h2][w2] = -1;


}

int main() {
    dp[1][1][1][1] = -1;
    int h1, h2, w1, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    if (ans(w1, h1, w2, h2) == 1) {
        cout << "W" << el;
    } else {
        cout << "L" << el;
    }


}
