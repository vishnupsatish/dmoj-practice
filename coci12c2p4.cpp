#include <bits/stdc++.h>

using namespace std;

// Two cases, then use sets and sorting
// to determine the best thing to do at each step. Note that the
// best Ai will always be chosen, since if it wasn't chosen with
// the best B, it will be chosen in the K - 1 case, otherwise, it
// will chosen with the best B.

int n;
multiset<int> una, amb;
vector<pair<int, int>> ba;


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int ae, be; cin >> ae >> be;
        ba.emplace_back(be, -ae);
        una.emplace(ae);
    }

    sort(ba.begin(), ba.end());

    long long sum_of_k = 0;

    for (int k = 1; k <= n; k++) {
        long long ans = 1e18;

        // Case 1
        if (k > 1) {
            auto it = una.find(abs(ba[k - 2].second));
            una.erase(it);
        }
        ans = min(ans, sum_of_k + *una.begin());

        sum_of_k += ba[k - 1].first;

        // Case 2
        amb.emplace(abs(ba[k - 1].second) - ba[k - 1].first);
        ans = min(ans, sum_of_k + *amb.begin());

        cout << ans << '\n';
    }
}
