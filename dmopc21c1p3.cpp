#include <bits/stdc++.h>

using namespace std;

// Idea: Imagine we are given two acyclic graphs and not connected to each other.
// If we want to connect the two graphs and make the resulting graph acyclic, all
// we need to do is direct all edges from the first graph to the second graph. We
// can use DSU to store each acyclic graph, then query a component and another component.
// We can then reverse all edges so they go from 'another component' to 'component'. Then,
// we merge those components since we know that they are connected eventually and are acyclic
// and since all edges between them go to from 'another component' to 'component'

// If there are no nodes that go from a set A and a set B, we just union sets A and B and
// move on since then we have confirmed that in that set of nodes all nodes go from
// A -> B so therefore it is acyclic.

const int MAXN = 303;
const int MAXM = 44853;

int n, m, edges[MAXM];

struct DSU {
    vector<int> children[MAXN];
    vector<int> comps;
    int num;

    DSU(int elems) {
        for (int i = 1; i <= elems; i++) {
            dsu[i] = i;
            children[i].emplace_back(i);
            comps.emplace_back(i);
        }
        num = elems;
    }

    int get(int e) {
        if (e != dsu[e]) dsu[e] = get(dsu[e]);
        return dsu[e];
    }

    void merge(int u, int v) {
        int fdv = get(v), fdu = get(u);
        if (fdv == fdu) return;
        children[fdv].insert(children[fdv].end(), children[fdu].begin(), children[fdu].end());
        children[fdu].clear();
        comps.erase(find(comps.begin(), comps.end(), fdu));
        num--;
        dsu[fdu] = fdv;
    }

    private:
        int dsu[MAXN]{};
};

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int useless1, useless2; cin >> useless1 >> useless2;
    }

    DSU dsu(n);

    while (dsu.num != 1) {
        for (int c = 0; c < dsu.num - 1; c++) { // We increment c by one since when we merge two nodes it removes one of the elements in the comps vector
            int u = dsu.comps[c], v = dsu.comps[c + 1];
            cout << "? " << dsu.children[u].size() << ' ' << dsu.children[v].size() << endl;
            for (int i = 0; i < dsu.children[u].size(); i++) cout << dsu.children[u][i] << (i != dsu.children[u].size() - 1 ? ' ' : '\n');
            for (int i = 0; i < dsu.children[v].size(); i++) cout << dsu.children[v][i] << (i != dsu.children[v].size() - 1? " " : "");
            cout << endl;
            int num; cin >> num;
            dsu.merge(u, v);
            while (num--) {
                int e; cin >> e;
                edges[e] = 1;
            }
        }
    }

    cout << "! ";
    for (int i = 1; i <= m; i++) cout << edges[i];
    cout << '\n';
}
