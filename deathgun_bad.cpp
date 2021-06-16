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
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque<int>

#define uset unordered_set


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------

const int MM = 1001;

int m;
map<string, int> ind;
vector<string> ans;
queue<string> z;
map<string, vector<string>> adj;
map<string, bool> vis;


int main() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string a, b; cin >> a >> b;
        adj[a].eb(b);
        ind[b]++;
    }

    for (auto [k, v] : adj) {
        if (ind[k] == 0) z.push(k);
    }

    while (!z.empty()) {
        string u = z.front(); z.pop();
        vis[u] = true;
        ans.eb(u);
        for (auto &v : adj[u]) {
            ind[v]--;
            if (!ind[v]) {
                z.push(v);
            }
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {

        bool con = false;
        for (auto &e : adj[ans[i]]) {
            if (!vis[e]) {
                con = true;
            }
        }

        if (con) continue;

        cout << ans[i] << el;
    }


}
