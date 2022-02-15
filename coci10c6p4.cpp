#include <bits/stdc++.h>

using namespace std;

// Idea: if prev characters are the same, the next characters
// determine how the letters are lexicographically ordered.
// Use topo sort. "?" case (when there is more than one solution)
// occurs when there is more than one node with indegree 0 in
// the topo sort and outside it (when adding to queue in the start)

const int MAXN = 102;

int n, ind[27];
string a[MAXN];
unordered_set<char> adj[27];
unordered_set<char> chars;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    memset(ind, -1, sizeof(ind));

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        for (auto c : a[i]) {
            chars.emplace(c);
        }
    }

    for (auto c : chars) {
        ind[c - 'a'] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = 0;

            while (a[i][k] == a[j][k] && k < a[i].size() && k < a[j].size()) {
                k++;
            }

            if (k < a[i].size() && k < a[j].size()) {
                if (!adj[a[i][k] - 'a'].contains(a[j][k])) {
                    ind[a[j][k] - 'a']++;
                }

                adj[a[i][k] - 'a'].emplace(a[j][k]);
            }
        }
    }

    string ans;

    queue<char> q;

    for (auto c : chars) {
        if (ind[c - 'a'] == 0) {
            if (!q.empty()) {
                cout << '?' << '\n';
                return 0;
            }

            q.emplace(c);
        }
    }

    while (!q.empty()) {
        char u = q.front(); q.pop();

        ans += u;

        int done = false;

        for (auto v : adj[u - 'a']) {
            if (--ind[v - 'a'] == 0) {
                if (done) {
                    cout << '?' << '\n';
                    return 0;
                }

                q.emplace(v);
                done = true;
            }
        }
    }

    if (ans.size() != chars.size()) {
        cout << "!" << '\n';
        return 0;
    }

    cout << ans << '\n';
}
