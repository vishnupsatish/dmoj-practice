#include <bits/stdc++.h>

using namespace std;

// Idea: for each pair (u, v) if u comes before v in all of the voters' list, create a
// directed edge from u -> v. Answer is the longest path in the DAG because it shows that the
// path is a list of valid candidates since they all appear in order in every voter's vote

const int MAXK = 27;

int n, k, ind[MAXK], path[MAXK], ans;
unordered_set<int> adj[MAXK], og_adj[MAXK];


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;

    // Create DAG; if person u is before person v in everyone's votes, create a directed edge from u to v for every pair (u, v)
    while (n--) {
        string s; cin >> s;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (og_adj[s[j] - 'A'].contains(s[i] - 'A')) {
                    if (adj[s[j] - 'A'].contains(s[i] - 'A')) {
                        adj[s[j] - 'A'].erase(s[i] - 'A');
                    }
                } else {
                    adj[s[i] - 'A'].emplace(s[j] - 'A');
                }
                og_adj[s[i] - 'A'].emplace(s[j] - 'A');
            }
        }
    }

    // Topological sort
    for (int u = 0; u < k; u++) {
        for (auto v : adj[u]) {
            ind[v]++;
        }
    }

    queue<int> q;

    for (int u = 0; u < k; u++) {
        if (!ind[u]) q.emplace(u);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : adj[u]) {
            if (--ind[v] == 0) q.emplace(v);
            path[v] = max(path[v], path[u] + 1);
            ans = max(ans, path[v]);
        }
    }

    cout << ans + 1 << '\n';
}
