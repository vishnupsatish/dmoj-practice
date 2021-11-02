#include <bits/stdc++.h>

using namespace std;

const int MAXN = 52;

int dist[MAXN], lvl[MAXN];
unordered_set<int> adj[MAXN];

void setup() {
    adj[1] = {6};
    adj[2] = {6};
    adj[3] = {4, 5, 6, 15};
    adj[4] = {3, 5, 6};
    adj[5] = {3, 4, 6};
    adj[6] = {1, 2, 3, 4, 5, 7};
    adj[7] = {6, 8};
    adj[8] = {7, 9};
    adj[9] = {8, 10, 12};
    adj[10] = {9, 11};
    adj[11] = {10, 12};
    adj[12] = {9, 11, 13};
    adj[13] = {12, 14, 15};
    adj[14] = {13};
    adj[15] = {3, 13};
    adj[16] = {17, 18};
    adj[17] = {16, 18};
    adj[18] = {16, 17};
}


pair<int, int> number_of_friends(int start, int end) {
    unordered_set<int> vis;
    vis.insert(start);
    queue<int> q;
    int ans = 0;
    q.push(start);
    memset(dist, 0, sizeof(dist));
    memset(lvl, 0, sizeof(lvl));

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (!vis.contains(v)) {
                dist[v] = dist[u] + 1;
                vis.insert(v);
                q.push(v);
                lvl[v] = lvl[u] + 1;
                if (lvl[v] == 2) {
                    ans++;
                }
            }
        }
    }
    return {ans, dist[end]};
}


int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);

    setup();

    char cmd; cin >> cmd;

    while (cmd != 'q') {
        switch (cmd) {

            case 'i': {
                int u, v; cin >> u >> v;
                adj[u].insert(v);
                adj[v].insert(u);
                break;
            }

            case 'd': {
                int u, v; cin >> u >> v;
                adj[u].erase(v);
                adj[v].erase(u);
                break;
            }

            case 'f': {
                int u; cin >> u;
                cout << number_of_friends(u, 0).first << '\n';
                break;
            }

            case 'n': {
                int u; cin >> u;
                cout << adj[u].size() << '\n';
                break;
            }

            case 's': {
                int u, v; cin >> u >> v;
                int ans = number_of_friends(u, v).second;
                if (ans == 0) cout << "Not connected" << '\n';
                else cout << ans << '\n';
            }
        }
        cin >> cmd;
    }
}
