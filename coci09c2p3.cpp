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

#define dq deque<int>

#define uset unordered_set


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------

const int MM = 11;

int n, k, ini[MM], ang[MM];
uset<int> sol[361];
uset<int> all;

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> ini[i];
    }

    sol[0].insert(0);
    all.insert(0);

    for (int i = 1; i < 360; i++) {
        for (auto old : sol[i - 1]) {
            for (int j = 1; j <= n; j++) {
                sol[i].insert((old + ini[j]) % 360);
                all.insert((old + ini[j]) % 360);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        cout << (all.contains(x) ? "YES" : "NO") << el;
    }

}