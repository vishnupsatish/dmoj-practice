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
#define pll pair<long long, long long>
#define mp make_pair
#define el "\n"
#define pq priority_queue
#define ll long long
#define ld long double
#define ull unsigned long long
#define mt make_tuple
#define vi vector<int> lol
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

// Idea: For every character, the previous character's value has an impact on the current subsequence.
// A character's value represents the number of subsequences of the string containing all chars up to
// the current one. For example, in lloo, looking for lo, at the ls you would increment the l counter,
// then at the os you would increment o counter with the value of the l counter, since, for each o,
// there are l subsequences of lo, leading to a total answer of 4

string a;
umap<char, ll> cnt;

void solve() {
    cin >> a;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'l') cnt['l']++;
        else if (a[i] == 'o') cnt['o'] += cnt['l'];
        else if (a[i] == 'v') cnt['v'] += cnt['o'];
        else if (a[i] == 'e') cnt['e'] += cnt['v'];
    }

    cout << cnt['e'] << el;
}


int main() {
    fastio();
    int T = 1;
//    cin >> T;
    while (T--) solve();
}
