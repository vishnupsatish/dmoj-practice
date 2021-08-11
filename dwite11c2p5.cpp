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
//#define vi vector<int> lol
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

const int MAXN = 1e5 + 3;

int n, dsu[MAXN];
umap<string, int> s2i;


int find(int e) {
    if (e != dsu[e]) dsu[e] = find(dsu[e]);
    return dsu[e];
}


void solve() {
    s2i.clear();
    int cur = 0;

    cin >> n;

    for (int i = 1; i < n; i++) dsu[i] = i;

    while (n--) {
        char q; string u, v; cin >> q >> u >> v;
        if (q == 'p') {
            int ui, vi;
            if (s2i.contains(u)) ui = s2i[u];
            else {
                ui = cur++;
                s2i[u] = ui;
            }

            if (s2i.contains(v)) vi = s2i[v];
            else {
                vi = cur++;
                s2i[v] = vi;
            }

            dsu[find(ui)] = find(vi);
        } else {

            if (u == v) {
                cout << "connected" << el; continue;
            }

            int ui, vi;
            if (s2i.contains(u)) ui = s2i[u];
            else {
                cout << "not connected" << el;
                continue;
            }

            if (s2i.contains(v)) vi = s2i[v];
            else {
                cout << "not connected" << el;
                continue;
            }

            if (find(ui) == find(vi)) cout << "connected" << el;
            else cout << "not connected" << el;
        }
    }
}


int main() {
    fastio();
    int T = 5;
//    cin >> T;
    while (T--) solve();
}
