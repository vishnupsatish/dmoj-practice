#include <bits/stdc++.h>

using namespace std;

// Greedy. Optimal idea: one is forwards, other is reverse, pair adjacent ones. Except a and b <= 100 
// and n <= 1e5 so take advantage of a and b. Store each occurrences in a map, then increment iterator 
// if there is an overlap so we don't need to calculate the same two numbers twice, ever. Total complexity
// is O(N * max(Ai, Bi))

int n;
map<int, int> ap;
map<int, int, greater<>> bp;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int ae, be; cin >> ae >> be;

        ap[ae]++;
        bp[be]++;

        map<int, int> a = ap;
        map<int, int, greater<>> b = bp;

        int ans = 0;

        auto it1 = a.begin();
        auto it2 = b.begin();

        while (it1 != a.end() || it2 != b.end()) {
            ans = max(ans, it2->first + it1->first);
            if (it1->second == it2->second) {
                it2++;
                it1++;
            } else if (it1->second > it2->second) {
                it1->second -= it2->second;
                it2++;
            } else {
                it2->second -= it1->second;
                it1++;
            }
        }

        cout << ans << '\n';
    }
}
