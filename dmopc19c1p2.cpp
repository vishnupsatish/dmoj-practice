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

// I hate this problem. Use recursion and length of each string to determine where the character is located.

int q;
string effofzero = "Good writing is good writing is good writing.";
string part1 = "Good writing is good ";
string part2 = " writing is good ";
string part3 = " is good writing.";
umap<int, ll> len;


char ans(int n, int k) {
    if (len[n] < k) return '.';
    if (n == 0) return effofzero[k - 1];
    ll len_of_effofminusone = len[n - 1];

    if (k <= 21) return part1[k - 1];

    if (k > 21 && k <= len_of_effofminusone + 21) return ans(n - 1, k - 21);

    if (k > 21 + len_of_effofminusone && k <= 38 + len_of_effofminusone) return part2[k - len_of_effofminusone - 21 - 1];

    if (k > 21 + len_of_effofminusone + 17 && k <= 21 + len_of_effofminusone + 17 + len_of_effofminusone) return ans(n - 1, k - 21 - len_of_effofminusone - 17);

    if (k > 21 + len_of_effofminusone + 17 + len_of_effofminusone && k <= 21 + len_of_effofminusone + 17 + len_of_effofminusone + 17) return part3[k - 21 - 17 - len_of_effofminusone - len_of_effofminusone - 1];
    return '.';
}


void solve(int case_number) {

    ll add = 100;
    len[0] = 45;
    for (int i = 1; i <= 30; i++) {
        len[i] = len[i - 1] + add;
        add *= 2;
    }

    cin >> q;

    while (q--) {
        int n, k; cin >> n >> k;
        cout << ans(n, k) << el;
    }
}


signed main() {
    fastio();
    int T = 1;
//    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
}
