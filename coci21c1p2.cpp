#include <bits/stdc++.h>

using namespace std;

// Idea: Kind of like interval DP. dp[beg][end][cur] represents the answer from
// beg -> end in the string and when the current person has cur red pebbles. To
// determine how many pebbles the other person has, it is
// psa[n] - cur - (psa[end] - psa[beg - 1]). Try to pick out from both ends of
// the pebbles and determine the answer using game theory.

const int MAXN = 350 + 3;

int n, k, psa[MAXN], memo[MAXN][MAXN][MAXN];
string s;


bool solve(int beg, int end, int cur) { // Returns 1 if the current player wins.
    int other_person = psa[n] - cur - (psa[end + 1] - psa[beg]);

    if (memo[beg][end][cur] != -1) return memo[beg][end][cur];
    if (cur == k) return true;
    if (other_person == k) return false;

    return memo[beg][end][cur] = !solve(beg, end - 1, other_person + (s[end] == 'C')) | !solve(beg + 1, end, other_person + (s[beg] == 'C'));
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    cin >> n >> k >> s;

    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + (s[i - 1] == 'C');
    }

    cout << (solve(0, n - 1, 0) ? "DA" : "NE") << '\n';
}
