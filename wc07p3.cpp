#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int n, t, w, p[16][16], dp[16][1 << 16];
vector <int> adj[16];

int func(int node, int mask) {
    if (dp[node][mask] > 0) return dp[node][mask];
    if (node == n - 1) return 1;
    for (int a : adj[node]) {
        if ((mask & 1 << a) == 0) {
            dp[node][mask] += func(a, mask | 1 << a);
            dp[node][mask] %= 13371337;
        }
    }
    return dp[node][mask];
}


int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {\
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int j = 0; j < 17; j++) {
            adj[j].clear();
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> w;
                if (w == 1) adj[j].push_back(k);
            }
        }
        cout << func(0, 1) << endl;
    }
    return 0;
}