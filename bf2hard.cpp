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

const int MAXN = 1e6 + 3;

int k, base = 131;
char s[MAXN];
ll hsh[MAXN], pw[MAXN];


ll get_sub_hash(int l, int r) {
    return hsh[r] - hsh[l - 1] * pw[r - l + 1];
}


int main() {
    scanf("%s %d", s + 1, &k);

    int n = strlen(s + 1);

    pw[0] = 1;

    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * base;
        hsh[i] = hsh[i - 1] * base + s[i];
    }

    int pos = 1;

    for (int i = 2; i + k - 1 <= n; i++) {
        if (s[i] < s[pos]) pos = i;
        else if (s[i] == s[pos]) {
            int lo = 0, hi = k - 1, dif = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (get_sub_hash(pos, pos + mid) == get_sub_hash(i, i + mid)) lo = mid + 1;
                else {
                    dif = mid; hi = mid - 1;
                }
            }
            if (s[pos + dif] > s[i + dif]) pos = i;
        }
    }

    for (int i = pos; i < pos + k; i++) printf("%c", s[i]);
}
