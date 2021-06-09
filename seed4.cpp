#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
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

#define fastio() cin.tie(0);ios::sync_with_stdio(0);

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
#define vpl vector<pl>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>

#define ti3 tuple<int, int, int>
#define tll3 tuple<ll, ll, ll>
#define mt make_tuple


using namespace std;

int n; ll x, y, z;

set<tll3> slo;

int main() {

    fastio();

    cin >> x >> y >> z >> n;


    for (int i = 0; i < n; i++) {
        ll xi, yi, zi;
        cin >> xi >> yi >> zi;
        ll dix = xi - x; ll diy = yi - y; ll diz = zi - z;
        ll gc_d = gcd(gcd(abs(dix), abs(diy)), abs(diz));
        dix /= gc_d; diy /= gc_d; diz /= gc_d;

        slo.emplace(dix, diy, diz);


    }

    cout << slo.size() << el;

}