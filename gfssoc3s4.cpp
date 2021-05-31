#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;


int R, C; vector<int> valid, adj[3000]; long long ans, dp[100][3000];


int main() {


    cin >> R >> C;

    // Determine valid combinations of bits in one row, there needs to be two spaces to avoid overlap
    for (int mask = 0; mask < 1 << C - 2; mask++) {
        if ((mask & mask >> 1) == 0 && (mask & mask >> 2) == 0) {
            valid.push_back(mask);
        }
    }

    // Determine valid combs across rows, since there needs to be two spaces between rows
    for (int i = 0; i < valid.size(); i++) {
        int mask = valid[i]; dp[0][i] = 1; ans++ ;
        for (int j = 0; j < valid.size(); j++) {
            int mask2 = valid[j] | valid[j] << 1 | valid[j] >> 1;
            if ((mask & mask2) == 0) adj[i].push_back(j);
        }
    }
    // Remove empty
    ans -= dp[0][0];

    // Go through each valid set of elements across rows, and add and mod answer
    for (int r=1; r<R - 1; r++) {
        for (int i = 0; i < valid.size(); i++) {
            for (int j: adj[i]) { dp[r][i] += dp[r - 1][j]; }
            dp[r][i] %= mod; ans = (ans + dp[r][i]) % mod;

        }
        ans = (ans - dp[r][0] + mod) % mod;
    }

    cout << ans << endl;


    return 0;

}