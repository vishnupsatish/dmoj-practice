#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>
#include <deque>

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

#define di deque<int>


using namespace std;

int n, k, vis[21];
vi adj[21];
int cyc;


void dfs(int u, int og) {
    vis[u] = 1;
    for (auto &v : adj[u]) {
        if (v == og) cyc = 1;
        else if (!vis[v]) dfs(v, og);
    }
}


int main() {
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c > d) adj[a].emplace_back(b);
        else adj[b].emplace_back(a);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, i);
        if (cyc) ans++;
        cyc = 0;
    }

    cout << ans << el;


}
