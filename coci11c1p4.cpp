#include <bits/stdc++.h>

using namespace std;

// Idea: for boys_taller, choose the shortest girl taller than the current boy.

int n, ans;
multiset<int> boys_shorter, boys_taller, girls_shorter, girls_taller; // than themselves

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        if (b <= 0) boys_shorter.insert(abs(b));
        else boys_taller.insert(b);
    }

    for (int i = 1; i <= n; i++) {
        int g; cin >> g;
        if (g <= 0) girls_shorter.insert(abs(g));
        else girls_taller.insert(g);
    }

    for (auto b: boys_taller) {
        auto it = girls_shorter.upper_bound(b);
        if (it != girls_shorter.end() && *it != 0) {
            ans++; girls_shorter.erase(it);
        }
    }

    for (auto b: girls_taller) {
        auto it = boys_shorter.upper_bound(b);
        if (it != boys_shorter.end() && *it != 0) {
            ans++; boys_shorter.erase(it);
        }
    }

    cout << ans << '\n';
}
