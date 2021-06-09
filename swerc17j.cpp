#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cstring>

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>


using namespace std;

int n;
ll a0, a1, a2, b0, b1, b2;


int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (i % 3 == 0) a0 += a;
        if (i % 3 == 1) a1 += a;
        if (i % 3 == 2) a2 += a;
    }

    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        if (i % 3 == 0) b0 += b;
        if (i % 3 == 1) b1 += b;
        if (i % 3 == 2) b2 += b;
    }

    cout << a0 * b0 + a1 * b2 + a2 * b1 << " " << a0 * b1 + a1 * b0 + a2 * b2 << " " << a1 * b1 + a2 * b0 + b2 * a0 << el;

}