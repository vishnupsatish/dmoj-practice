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

int main() {
    fastio();

    cin >> t;

    while (t--) {
        int r1, r2, r3; cin >> r1 >> r2 >> r3;

        int denominator = (r2 - r3) * (r2 - r3);
        int numerator = 0;

        if (r1 - r3 > 0) numerator += max(0, (r1 - r3) * (r1 - r3));
        
        numerator += max(0, ((r2 - r3) * (r2 - r3)) - ((r1 + r3) * (r1 + r3)));

        if (r3 > r1) numerator += min(((r3 - r1) * (r3 - r1)), ((r2 - r3) * (r2 - r3)));

        cout << (double)numerator / (double)denominator << el;
    }
}

