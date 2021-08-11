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

int n;
const int max_elem = 32768 + 3;
multiset<ll> a;
multiset<ll> b;

int main() {
    fastio();

    cin >> n;

    for (int i = 1; i <= 2*n+1; i++) {
        int e; cin >> e; a.insert(e);
    }

    for (int i = 1; i <= 2*n+1; i++) {
        int e; cin >> e; b.insert(e);
    }

    for (int i = 0; i <= max_elem; i++) {
        multiset<ll> ne;
        for (auto x : a) ne.insert(x ^ i);
        if (ne == b) {
            cout << i << el;
            return 0;
        }
    }

    cout << -1 << el;
}
