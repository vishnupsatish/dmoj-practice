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
#define pll pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

#define vi vector<int>

#define pb push_back
#define eb emplace_back

#define mt make_tuple

#define dq deque

#define uset unordered_set

#define umap unordered_map


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

int k;
vi primes;
vector<pi> ans; // first is prime index, second is actual num
int si[700];

int arithmetic_sequence(int a) {
    return a * (long double)(a + 1) / 2;
}

int bs(int a) {
    int l = 1; int r = 101;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arithmetic_sequence(mid) > a) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return (arithmetic_sequence(l) == a ? l + 1 : l);
}

void sieve() {
    memset(si, -1, sizeof(si));
    si[0] = 0;
    si[1] = 0;
    for (int i = 2; i <= 600; i++) {
        if (si[i] == -1) {
            for (int j = 2; j <= 600/i + 1; j++) {
                si[i * j] = 0;
            }
        }
    }


    for (int i = 2; i <= 600; i++) {
        if (si[i] == -1) {
            primes.eb(i);
        }
    }
}


int main() {
    cin >> k;

    sieve();

    while (k != 0) {
        int a = bs(k); k -= arithmetic_sequence(a - 1);
        if (ans.empty()) ans.eb(1, 2);
        else ans.eb(ans.back().fi + 1, ans.back().se * 2);
        for (int i = 2; i <= a; i++) {
            ans.eb(ans.back().fi + 1, primes[ans.back().fi + 1]);
        }
    }

    cout << ans.size() << el;

    for (int i = 0; i < ans.size(); i++) cout << ans[i].se << (i != ans.size() - 1 ? " " : el);

}
