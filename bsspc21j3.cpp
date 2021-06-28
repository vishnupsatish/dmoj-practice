#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
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

int m, n;
umap<char, vector<char>> cart = {{'R', {'r'}},
                                 {'U', {'b'}},
                                 {'Y', {'y'}},
                                 {'O', {'r', 'y'}},
                                 {'G', {'b', 'y'}},
                                 {'P', {'r', 'b'}},
                                 {'B', {'r', 'b', 'y'}},
                                 };
bool r, y, b;
uset<int> ad;
uset<int> temp;
umap<char, int> ans;


int main() {

    fastio();

    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            temp.clear();
            if (j == 1 || c == '.') ad.clear();

            for (auto e : cart[c]) {
                if (!ad.contains(e)) {
                    ans[e] += 1;
                    ad.insert(e);
                }
                temp.insert(e);
            }
            ad = temp;
        }
    }

    cout << ans['r'] << " " << ans['y'] << " " << ans['b'] << el;

}

