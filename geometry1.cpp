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
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>
#define si stack<int>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>
#define dqll deque<long long>

#define sei set<int>
#define sepi set<pair<int, int>>

#define mii map<int, int>
#define mpii map<int, pair<int, int>>

using namespace std;

//---------------End of template-------------------------------


const long double two = 2;
int n;
long double x1, y1_, x2, y2, x3, y3;

int main() {
    cin >> n;
    for (int t = 0; t < n; t++) {
        cin >> x1 >> y1_ >> x2 >> y2 >> x3 >> y3;
        long double s1 = sqrt(pow(abs(y2 - y1_), 2) + pow(abs(x2 - x1), 2));
        long double s2 = sqrt(pow(abs(y3 - y1_), 2) + pow(abs(x3 - x1), 2));
        long double s3 = sqrt(pow(abs(y2 - y3), 2) + pow(abs(x2 - x3), 2));
        long double sp = (s1 + s2 + s3) / two;
        long double ar = sqrt(sp * (sp - s1) * (sp - s2) * (sp - s3));

        cout << fixed << setprecision(2) << ar << " " << (s1 + s2 + s3) << el;
    }
}
