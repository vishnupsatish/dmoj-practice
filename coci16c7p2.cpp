#pragma GCC optimize("Ofast", "unroll-loops")

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

#define int long long // Solution uses patterns

int n;
uset<int> fact;
set<pii> ans;


ll accum(ld a, ld b) {
    ll ret = 0; for (int i = a; i <= b; i++) ret += i;
    return (a + b) / (ld)(2) * (b - a + 1);
}


signed main() {
    fastio();
    cin >> n;
    cout << fixed << setprecision(0);

    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (n % i == 0) {
            fact.insert(i);
            fact.insert(n / i);
        }
    }

    if (n % 2 == 1) cout << n / 2 << ' ' << n / 2 + 1 << el;

    for (auto f : fact) {
        ld ldf = (ld)(f);
        ld avg = (ld)(n) / ldf;
        if (accum(ceil(avg - ldf/2), floor(avg + ldf/2)) == n && avg - ldf/2 >= 0.5 && !ans.contains(mp(ceil(avg - ldf/2), floor(avg + ldf/2)))) {
            cout << ceil(avg - ldf/2) << " " << floor(avg + ldf/2) << el;
            ans.insert(mp(ceil(avg - ldf/2), floor(avg + ldf/2)));

        }

        ld avg2 = (ld) (n) / (ldf * 2);
        if (accum(ceil(avg2 - ldf), floor(avg2 + ldf)) == n && avg2 - ldf >= 0.5 && !ans.contains(mp(ceil(avg2 - ldf), floor(avg2 + ldf)))) {
            cout << ceil(avg2 - ldf) << " " << floor(avg2 + ldf) << el;
            ans.insert(mp(ceil(avg2 - ldf), floor(avg2 + ldf)));
        }


    }


}
