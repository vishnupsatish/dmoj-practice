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

// Hash T, hash S in array, then get substring hash in O(1)

const int MAXN = 1e6 + 3;

int base = 131;
ll hsh[MAXN], pw[MAXN], hash_t;
string s, t;


ll get_sub_hash(int l, int r) {
    return (hsh[r] - hsh[l - 1] * pw[r - l + 1]  % MOD + MOD) % MOD;
}


int main() {
    cin >> s >> t;

    for (int i = 0; i < t.length(); i++) {
        hash_t = (hash_t * base + t[i]) % MOD;
    }
    hsh[0] = 0; pw[0] = 1;

    for (int i = 1; i <= s.length(); i++) {
        pw[i] = pw[i - 1] * base % MOD;
        hsh[i] = (hsh[i - 1] * base + s[i - 1]) % MOD;
    }

    for (int i = 0; i + t.length() <= s.length(); i++) {
        if (get_sub_hash(i + 1, i + t.length()) == hash_t) {
            cout << i << el;
            return 0;
        }
    }
    cout << -1 << el;
}