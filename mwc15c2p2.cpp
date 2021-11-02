#include <bits/stdc++.h>

using namespace std;

// Idea: monotonic stack will hold indexes, and will be monotonically decreasing.
// Pop all from the top of the stack where current height is greater than the next
// element in the stack's height, since then in the future you can only see the
// current element, since it will be taller than the elements it popped, but shorter
// than the elements left in stack, meaning those can still be blocking the view of
// a future height. Then, subtract the current element and the stack's back, meaning,
// that is the first element that blocks the view.

const int MAXN = 1e6 + 3;

int n, h[MAXN];
vector<int> ms;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> h[i];

    for (int i = 0; i < n; i++) {
        while (!ms.empty() && h[i] >= h[ms.back()]) ms.pop_back();
        if (ms.empty()) cout << i << ' ';
        else cout << i - ms.back() << ' ';
        ms.emplace_back(i);
    }
}
