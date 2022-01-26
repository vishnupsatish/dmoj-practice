#include <bits/stdc++.h>

using namespace std;

// Idea: directed graph. if A -> B, then the character replacing A must be less than the
// character replacing B. If prefix of a larger string is later, then break and print NE.
// Use topo sort to determine the lexo smallest character then replace.

const int MAXN = 103;

int n, mss, a[MAXN], ind[26]; // mss: max string size
unordered_map<char, char> enc;
vector<pair<int, string>> s;
unordered_set<int> adj[26];
unordered_set<int> nodes;
vector<int> topo;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string c; cin >> c;
        mss = max(mss, (int)c.size());
        s.emplace_back(0, c);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i] - 1].first = i;
    }

    sort(s.begin(), s.end());

    // Build directed graph: if A -> B, then the character replacing A must be less than the character replacing B
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string w1 = s[i].second, w2 = s[j].second;

            // Check if prefix
            if (w1.find(w2) == 0) {
                cout << "NE" << '\n';
                return 0;
            }

            for (int k = 0; k < min(w1.size(), w2.size()); k++) {
                if (w1[k] != w2[k]) {
                    adj[w1[k] - 'a'].emplace(w2[k] - 'a');
                    nodes.emplace(w1[k] - 'a');
                    nodes.emplace(w2[k] - 'a');
                    break;
                }
            }
        }
    }

    // Topological sort to determine the least character (replace it with a 'a')

    queue<int> q;

    for (auto u : nodes) {
        for (auto v : adj[u]) {
            ind[v]++;
        }
    }

    for (auto u : nodes) {
        if (ind[u] == 0) {
            q.emplace(u);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);

        for (auto v : adj[u]) {
            if (--ind[v] == 0) q.emplace(v);
        }
    }

    if (topo.size() != nodes.size()) {
        cout << "NE" << '\n';
        return 0;
    }

    for (int i = 0; i < topo.size(); i++) {
        enc[topo[i] + 'a'] = i + 'a';
    }

    unordered_set<char> in_enc;

    for (auto [k, v] : enc) in_enc.emplace(v);

    vector<char> alphabet;

    cout << "DA" << '\n';

    for (char c = 'a'; c <= 'z'; c++) {
        if (!in_enc.contains(c)) alphabet.emplace_back(c);
    }

    int cnt = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        if (enc.contains(c)) cout << enc[c];
        else cout << alphabet[cnt++];
        cout << (c == 'z' ? "\n" : "");
    }
}
