#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque

#define uset unordered_set


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

const int MAXN = 1e5 + 2;

int n, m, ar[MAXN], ans;


int main() {

    fastio();

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> ar[i]; ans += ar[i];
    }

    cin >> m;

    for (int i = 1; i <= m; i++) {
        int a, d; cin >> a >> d;
        ans -= min(min(ar[a], ar[a + 1]), d);
    }

    cout << ans << el;

}

