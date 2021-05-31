#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <bitset>

#define pi pair<int, int>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

using namespace std;



int N, K;

vector<int> valid, adj[3000]; long long ans, dp[11][101][1 << 11];


int main() {

    cin >> N >> K;

    for (int mask = 0; mask < 1 << N; mask++) {
        if ((mask & mask >> 1) == 0) {
            valid.push_back(mask);
        }
    }


    for (int i = 0; i < valid.size(); i++) {
        int mask = valid[i]; dp[1][__builtin_popcount(valid[i])][i] = 1;
        for (int j = 0; j < valid.size(); j++) {
            int mask2 = valid[j] << 1 | valid[j] >> 1 | valid[j];

            if ((mask & mask2) == 0) {adj[i].push_back(j);}
        }
    }


    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int p = 0; p < valid.size(); p++) {
                if (j < __builtin_popcount(valid[p])) continue;
                for (int q: adj[p]) { dp[i][j][p] += dp[i - 1][j - __builtin_popcount(valid[p])][q]; }
            }
        }
    }

    for (int i = 0; i < valid.size(); i++) ans += dp[N][K][i];

    cout << ans << endl;

    return 0;



}
