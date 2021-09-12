#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <functional>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>
#endif

#define fastio() cin.tie(0);ios::sync_with_stdio(0);
#define fi first
#define se second
#define el "\n"
#define ll long long
#define ld long double
#define vi vector<int>
#define eb emplace_back
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

// Idea: stack is monotonously decreasing. when you pop if it's too big,
// all of those elements can be seen by the current element. Special case
// is if two elems are equal then add to second element in pair (since they
// can see each other, and the next tallest element in the stack)

int n;
stack<pair<int, int>> s;
ll ans;

int main() {
    fastio();

    cin >> n;

    while (n--) {
        int h; cin >> h;

        while (!s.empty() && s.top().fi < h) {
            ans += s.top().se; s.pop();
        }

        if (s.empty()) s.emplace(h, 1);
        else {
            if (s.top().fi == h) {
                ans += (s.top().se) + (s.size() > 1);
                s.top().se++;
            } else {
                ans++; s.emplace(h, 1);
            }
        }
    }

    cout << ans << el;
}



