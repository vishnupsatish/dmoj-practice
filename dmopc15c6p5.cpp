#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

// Idea: two pointers and use two monotonic queues to store the min and max
// element of a window, respectively. The idea is pretty simple but originally
// I used a multiset so changing it to use monoqueues was cancer.

const int MAXN = 3e6 + 3;

int n, k, a[MAXN];
long long ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = 1, ma = a[1], mi = a[1];
    deque<pair<int, int>> inc_mono, dec_mono;

    inc_mono.emplace_back(a[1], 1);
    dec_mono.emplace_back(a[1], 1);

    while (r <= n) {
        ans++; // l and r are positioned to always work
        if (r != 1) { // Add a[r] to the monoqueue
            while (!inc_mono.empty() && inc_mono.back().first >= a[r]) inc_mono.pop_back();
            inc_mono.emplace_back(a[r], r);
            while (!dec_mono.empty() && dec_mono.back().first <= a[r]) dec_mono.pop_back();
            dec_mono.emplace_back(a[r], r);
        }
        // Update max and min elements accordingly
        ma = max(ma, a[r]);
        mi = min(mi, a[r]);
        if (max(ma, a[r + 1]) - min(mi, a[r + 1]) <= k) r++; // If [l, r + 1] is ok, then increment r since it works
        else { // Otherwise, increment l
            if (!dec_mono.empty() && dec_mono.front().second == l) dec_mono.pop_front(); // Monoqueue property! If l is in the queue, remove it
            if (!inc_mono.empty() && inc_mono.front().second == l) inc_mono.pop_front();
            l++;
            if (l == r + 1) { // If l and r were the same, we can't have l > r so increment r as well and add a[r] to the monoqueue
                r++;
                while (!inc_mono.empty() && inc_mono.back().first >= a[r]) inc_mono.pop_back();
                inc_mono.emplace_back(a[r], r);
                while (!dec_mono.empty() && dec_mono.back().first <= a[r]) dec_mono.pop_back();
                dec_mono.emplace_back(a[r], r);
            }
            // Update max and min elements accordingly
            ans += r - l;
            ma = dec_mono[0].first;
            mi = inc_mono[0].first;
        }
    }

    ans += ((r - l) * (r - l - 1)) / 2; // Count up the remaining subarrays

    cout << ans << '\n';
}
