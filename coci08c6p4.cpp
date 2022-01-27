#include <bits/stdc++.h>

using namespace std;

// Casework

const int MAXN = 1e4 + 2;

int n, a[MAXN];
vector<int> m[3];


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i]; m[a[i] % 3].emplace_back(a[i]);
    }

    vector<int> ans;

    if (m[0].size() > m[1].size() + m[2].size() + 1) { // Too many mod 0s and not enough mod 1s and mod 2s to separate
        cout << "impossible" << '\n';
        return 0;
    }

    if (!m[1].empty() && !m[2].empty() && m[0].empty()) { // Only consisting of mod 1s and mod 2s then there will be one adjacent sum that is div by 3
        cout << "impossible" << '\n';
        return 0;
    }

    if (m[0].empty()) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
        return 0;
    }

    int cur0 = 0, cur1 = 0, cur2 = 0;
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        if (cur1 == m[1].size() && !flag) { // All mod 1s are done, place a mod 0 to separate, then go to mod 2s
            cout << m[0][cur0++];
            flag = true;
        }
        else {
            if (i & 1 && cur0 < m[0].size() - (!flag)) cout << m[0][cur0++]; // If there is still a mod 0 and we don't need to leave one to place between mod 1 and mod 2, place it
            else {
                if (cur1 < m[1].size()) cout << m[1][cur1++]; // Place all mod 1s before mod 2s
                else cout << m[2][cur2++]; // Place all mod 2s
            }
        }
        cout << (i == n ? '\n' : ' ');
    }
}
