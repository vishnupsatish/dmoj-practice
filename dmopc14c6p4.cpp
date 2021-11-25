#include <bits/stdc++.h>

using namespace std;

// Idea: loop backwards, and if an element is too far away from the next,
// add a break to the next element, basically ceil add a number of breaks
// 'since while everything else goes down, that one stays the same during
// a break, so simulate that by making it go up

const int MAXN = 1e3 + 2;

#define double long double

int n, ans;
double m, h, t[MAXN];

int main() {
    cin >> n >> m >> h;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = n; i >= 1; i--) {
        double dif = t[i] - t[i - 1];
        double should_be = h;
        if (dif > should_be) {
            ans += ceil(((dif - should_be)) / m);
            t[i - 1] += ceil(((dif - should_be)) / m) * m;
        }
    }

    cout << ans << '\n';
}
