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
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define el "\n"
#define pq priority_queue
#define ll long long
#define ld long double
#define ull unsigned long long
#define mt make_tuple
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define dq deque
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

// Idea: for each letter, we can either choose any one of the occurrences of that letter or not choose any occurrence at all.
// Also think of it like this: say there is a distinct set x, if we determined all of the combinations of x, each element would
// appear n/2 times where n is the number of combinations. The same concept is applied here as well. Also think of binary numbers,
// you can set a bit (choose it), or not, and it is known that there are 2^n combinations

string s;
umap<char, int> a;
ll ans = 1;

void solve(int case_number) {
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        a[s[i]]++;
    }

    for (auto [_, x] : a) {
        ans *= (x + 1);
        ans %= MOD;
    }

    cout << ans << el;
}


signed main() {
    fastio();
    int T = 1;
//    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
}
