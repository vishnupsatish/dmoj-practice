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

const int MAXN = 10;

int n, a[MAXN][2];
ll ans = INF;

signed main() {
    fastio();

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    cont:for (int i = 1; i <= (1 << n) - 1; i++) {
        int sum = 0; ll mult = 1;
        string bin = bitset<10>(i).to_string();
        for (int j = 10 - n; j < 10; j++) {
            if (bin[j] == '1') {
                mult *= a[9 - j][0];
                sum += a[9 - j][1];
                if (mult < 0) { // If overflow, lolz
                    goto cont;
                }
            }
        }
        ans = min(ans, abs(mult - sum));
    }

    cout << ans << el;
}
