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

int t;


pii prime(ll num) {
    int two = 0;
    int five = 0;

    while (num % 2 == 0) {
        num /= 2;
        two++;
    }

    while (num % 5 == 0) {
        num /= 5;
        five++;
    }

    if (num != 1) return {-1, -1};

    return {two, five};
}


int main() {
    fastio();

    cin >> t;

    while (t--) {
        ll a, b; cin >> a >> b;
        ll gcf = gcd(a, b);
        b /= gcf;
        pii f = prime(b);
        if (f.fi != -1) cout << max(f.fi, f.se) << el;
        else cout << -1 << el;
    }

}
