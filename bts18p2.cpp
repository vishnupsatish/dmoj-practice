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

// Idea: PSA, one for each letter

const int MAXN = 1e6 + 3;

int q, psa[28][MAXN];
string s;


int get_char_index(char c) {
    return c % 32;
}


int main() {
    fastio();

    getline(cin, s);

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= 26; j++) {
            psa[j][i] = psa[j][i - 1] + (s[i - 1] != ' ' && j == get_char_index(s[i - 1]));
        }
    }

    cin >> q;

    while (q--) {
        int l, r; char c; cin >> l >> r >> c;
        int char_ind = get_char_index(c);
        cout << psa[char_ind][r] - psa[char_ind][l - 1] << el;
    }
}
