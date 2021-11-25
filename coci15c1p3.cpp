#include <bits/stdc++.h>

using namespace std;

// Idea: greedily hold all numbers in a sequence. say 5 is a
// sequence, then 4 appears, remove 5 and add 4. otherwise,
// just add the 4. answer is the size of the sequences remaining.

const int MAXN = 1e6 + 3;

int n, h[MAXN];
multiset<int> cs; // Holds the current sequences

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> h[i];

    for (int i = 1; i <= n; i++) {
        if (cs.find(h[i] + 1) != cs.end()) cs.erase(cs.find(h[i] + 1));
        cs.insert(h[i]);
    }

    cout << cs.size() << '\n';
}
