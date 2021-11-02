#include <bits/stdc++.h>

using namespace std;

const int MAXN = 302;

int n, q, pos[MAXN], cur[MAXN], a[MAXN];

// Idea: keep an array 'cur' which stores 1->n, and keep an array
// 'pos' which stores their indexes; if query is add to end, swap
// the indexes, if query is add to beginning, swap the indexes of
// the values (since we gotta pretend that the swap has been done this entire time)

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        pos[i] = cur[i] = i;
    }

    while (q--) {
        char c; cin >> c;
        if (c == 'B') {
            int u, v; cin >> u >> v;
            swap(cur[pos[u]], cur[pos[v]]);
            swap(pos[cur[pos[u]]], pos[cur[pos[v]]]);
        } else if (c == 'E') {
            int u, v; cin >> u >> v;
            swap(cur[u], cur[v]);
            swap(pos[cur[u]], pos[cur[v]]);
        } else {
            for (int i = 1; i <= n; i++) {
                int m; cin >> m;
                a[cur[i]] = m;
            }
            for (int i = 1; i <= n; i++) {
                cout << a[i] << (i != n ? " " : "\n");
            }
        }
    }
}