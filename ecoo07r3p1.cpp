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
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define el "\n"
#define pq priority_queue
#define ll long long
#define ld long double
#define ull unsigned long long
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

// Idea: start from a / 3 or a / 2 (depending on even or odd) then brute-force

const int MAXPRIME = 1e7 + 3;

int sieve[MAXPRIME];


int main() {
    fill(begin(sieve), end(sieve), 1);

    sieve[0] = 0; sieve[1] = 0;
    for (int i = 2; i < MAXPRIME; i++) {
        if (sieve[i]) {
            for (int j = 2; i * j < MAXPRIME; j++) {
                sieve[i * j] = 0;
            }
        }
    }
    sieve[2] = 0;


    int T = 5;
    while (T--) {
        int a; cin >> a;
        if (sieve[a]) cout << a << " = " << a << el;
        else if (a % 2 == 0) { // even
            for (int i = a / 2; i >= 3; i--) {
                if (sieve[a - i] && sieve[i]) {
                    cout << a << " = " << i << " + " << a - i << el;
                    goto nextcase;
                }
            }
        } else {
            for (int i = a / 3; i >= 3; i--) {
                if (sieve[i]) {
                    for (int j = (a - i) / 2; j >= 3; j--) {
                        if (sieve[j] && sieve[(a - i) - j] && j >= i) {
                            cout << a << " = " << i << " + " << j << " + " << (a - i) - j << el;
                            goto nextcase;
                        }
                    }
                }
            }
        }
        nextcase: continue;
    }
}