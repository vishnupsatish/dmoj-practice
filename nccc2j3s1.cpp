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

// Idea: if the largest element is larger than the sum of all of the other elements, then the best thing to do
// is to reduce the max element and any of the other ones, making the max elem > 0 and all other elems = 0.
// Otherwise, if the largest element is smaller than the sum of all of the other elements, then the best thing to do
// is to greedily choose the largest (to make all larger elems very small) and the smallest (to make it to 0) and repeat that process

int n, ma;
ll s;

int main() {
    fastio();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        s += b;
        ma = max(b, ma);
    }

    cout << min(s - ma, s / 2) << el;
}
