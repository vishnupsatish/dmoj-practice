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
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

int howmanytimesihavetorunthis;

signed main() {
    fastio();

    cin >> howmanytimesihavetorunthis;

    while (howmanytimesihavetorunthis--) {
        int m; cin >> m;
        map<int, int> seen;

        int loop;
        bool lp = false;

        int counter = 0;
        while (1) {
            int lg = log10(m);
            lg++;
            int nval = 0;
            for (auto c : to_string(m)) {
                nval += pow(((int)c - '0'), lg);
            }
            if (m == nval) {
                m = nval;
                break;
            }
            if (seen.contains(nval)) {
                lp = true;
                loop = counter - seen[nval] + 1;
                counter -= loop - 1; break;
            }
            counter++;
            seen[nval] = counter;
            m = nval;
        }
        if (lp) {
            cout << "Instability: Loop of length " << loop << " encountered after " << counter << " second(s)!" << el;
        } else {
            cout << "Equilibrium: Bob's investment becomes $" << m << " after " << counter << " second(s)!" << el;
        }
    }
}
