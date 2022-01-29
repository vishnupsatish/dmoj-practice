#include <bits/stdc++.h>

using namespace std;

// Idea: Greedily choose the next piece that fits and is lexicographically the least.
// Then, place an ending piece. If there are still type 2 and type 3 remaining, place
// them in the rightmost place possible. If there are 1s and 4s remaining, there is no
// valid answer since we cannot place them anywhere. Why does greedy work? What if by
// using the greedy the last piece doesn't fit, and why are there no other arrangements
// where the last piece does fit? If the last piece cannot fit, output -1, and there
// are no other arrangements that work because we have placed all type 1 and 4 pieces
// and types 1 and 4 cannot be adjacent to types 1 and 4, respectively, and if we place
// any 2s and 3s at the end, regardless of how many we place, the last thing will be the
// same as if that 2 or 3 wasn't there. Therefore, the greedy algorithm works.

int n, lst;
deque<int> ans;
deque<int> a[9];
unordered_map<int, int> nt; // Maps a number to the type


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    // Special case if n == 2 (I don't know if we actually need this or not)
    if (n == 2) {
        int t1, v1, t2, v2; cin >> t1 >> v1 >> t2 >> v2;
        if ((t1 == 5 && t2 == 8) || (t1 == 6 && t2 == 7)) cout << v1 << ' ' << v2 << '\n';
        else if ((t1 == 8 && t2 == 5) || (t1 == 7 && t2 == 6)) cout << v2 << ' ' << v1 << '\n';
        else cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        int x, num; cin >> x >> num;
        if (x == 5 || x == 6) ans.emplace_back(num);
        else if (x == 7 || x == 8) lst = num;
        a[x].emplace_back(num);
        nt[num] = x;
    }

    for (int i = 1; i <= 8; i++) sort(a[i].begin(), a[i].end());

    while (true) {
        int prev = ans.back();
        if (nt[prev] == 1 || nt[prev] == 3 || nt[prev] == 5) {
            int mi = 1e9 + 7;
            if (!a[3].empty()) mi = min(a[3].front(), mi);
            if (!a[4].empty()) mi = min(a[4].front(), mi);
            if (mi == 1e9 + 7) break;
            ans.emplace_back(mi);
            a[nt[mi]].pop_front();
        } else if (nt[prev] == 2 || nt[prev] == 4 || nt[prev] == 6) {
            int mi = 1e9 + 7;
            if (!a[1].empty()) mi = min(a[1].front(), mi);
            if (!a[2].empty()) mi = min(a[2].front(), mi);
            if (mi == 1e9 + 7) break;
            ans.emplace_back(mi);
            a[nt[mi]].pop_front();
        } else break;
    }

    if (nt[lst] == 8 && (nt[ans.back()] == 1 || nt[ans.back()] == 3)) {
        ans.emplace_back(lst);
        a[8].pop_back();
    }

    if (nt[lst] == 7 && (nt[ans.back()] == 2 || nt[ans.back()] == 4)) {
        ans.emplace_back(lst);
        a[7].pop_back();
    }

    if (!a[7].empty() || !a[8].empty() || !a[4].empty() || !a[1].empty()) {
        cout << -1 << '\n';
        return 0;
    }

    if (!a[2].empty()) {
        int pos = 1e9 + 7;
        for (int i = (int)ans.size() - 2; i >= 0; i--) {
            if (nt[ans[i]] == 2 || nt[ans[i]] == 4 || nt[ans[i]] == 6) {
                pos = i; // We need to add all remaining type 2s to the right of 'pos'
                break;
            }
        }
        if (pos == 1e9 + 7) {
            cout << -1 << '\n';
            return 0;
        }
        ans.insert(ans.begin() + pos + 1, a[2].begin(), a[2].end());
    }

    if (!a[3].empty()) {
        int pos = 1e9 + 7;
        for (int i = (int)ans.size() - 2; i >= 0; i--) {
            if (nt[ans[i]] == 1 || nt[ans[i]] == 3 || nt[ans[i]] == 5) {
                pos = i; // We need to add all remaining type 3s to the right of 'pos'
                break;
            }
        }
        if (pos == 1e9 + 7) {
            cout << -1 << '\n';
            return 0;
        }
        ans.insert(ans.begin() + pos + 1, a[3].begin(), a[3].end());
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
}
