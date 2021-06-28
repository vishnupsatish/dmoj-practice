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

#define str string

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

const int MAXPRIME = 2.17e5;

int x, k, q;
vi primes;
int prtemp[MAXPRIME + 200];
int psa[MAXPRIME];

int main() {

    fastio();

    memset(prtemp, -1, sizeof(prtemp));
    prtemp[0] = 0;
    prtemp[1] = 0;

    for (int i = 2; i <= MAXPRIME; i++) {
        if (prtemp[i] == -1) {
            for (int j = 2; i * j <= MAXPRIME; j++) {
                prtemp[i * j] = 0;
            }
        }
    }

    for (int i = 1; i < MAXPRIME; i++) {
        if (prtemp[i]) primes.eb(i);
    }

    psa[0] = 0;
    psa[1] = primes[0];

    for (int i = 1; i < primes.size(); i++) {
        psa[i + 1] = psa[i] + primes[i];
    }


    cin >> q;

    for (int i = 1; i <= q; i++) {
        cin >> x >> k;
        int ind = lower_bound(primes.begin(), primes.end(), x) - primes.begin() - 1;
        cout << primes[ind + k] << ' ' << psa[ind + k + 1] - psa[ind + 1] << el;
    }

}
