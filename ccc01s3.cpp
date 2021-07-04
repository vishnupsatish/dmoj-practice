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
#define ld long double
#define mt make_tuple
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

const int MAXN = 26;

int n, ans, dsu[MAXN + 3];
vector<pii> nodes;
umap<char, int> l2n = {{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4},
                                   {'E', 5}, {'F', 6}, {'G', 7}, {'H', 8},
                                   {'I', 9}, {'J', 10}, {'K', 11}, {'L', 12},
                                   {'M', 13}, {'N', 14}, {'O', 15}, {'P', 16},
                                   {'Q', 17}, {'R', 18}, {'S', 19}, {'T', 20},
                                   {'U', 21}, {'V', 22}, {'W', 23}, {'X', 24},
                                   {'Y', 25}, {'Z', 26}};

string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int find(int e) {
    if (e != dsu[e]) dsu[e] = find(dsu[e]);
    return dsu[e];
}


int main() {
    fastio();
    while (true) {
        char a, b; cin >> a >> b;
        if (a == '*') break;

        nodes.eb(l2n[a], l2n[b]);
        n++;
    }

    for (int i = 0; i < n; i++) { // Remove the edge i, and if A dsu != B dsu then print it
        for (int j = 1; j <= MAXN; j++) dsu[j] = j; // Reset dsu
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int u = nodes[j].fi, v = nodes[j].se;
            dsu[find(u)] = find(v);
        }

        if (find(1) != find(2)) {
            ans++;
            cout << letters[nodes[i].fi - 1] << letters[nodes[i].se - 1] << el;
        }
    }

    cout << "There are " << ans << " disconnecting roads." << el;
}
