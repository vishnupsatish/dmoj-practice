#include <bits/stdc++.h>

using namespace std;

// Idea: binary search for the value of L. Also logarithmize
// every single value so squaring becomes multiplication and
// dividing becomes subtraction (and therefore no precision
// is lost)

const int MAXN = 1003;

int n;
double k[MAXN];
vector<tuple<int, double, int>> adj[MAXN];


bool check(double l, int u, int par) {
    // Leaf node
    if (adj[u].size() == 1 && par != -1) return l >= k[u];

    bool ok = true;

    for (auto [v, x, t] : adj[u]) {
        if (v == par) continue;

        if (t) ok &= check((l - x) + (l - x), v, u);
        else ok &= check(l - x, v, u);
    }

    return ok;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int a, b, x, t; cin >> a >> b >> x >> t;
        adj[a].emplace_back(b, log10(100.0 / x), t);
        adj[b].emplace_back(a, log10(100.0 / x), t);
    }

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        k[i] = log10(k[i]);
    }

    int l = 0, r = 10000000;

    while (l < r) {
        int mid = (l + r) / 2;

        if (check(mid / 100000.0, 1, -1)) r = mid;
        else l = mid + 1;
    }

    cout << fixed << setprecision(3) << pow(10, l / 100000.0) << '\n';
}
