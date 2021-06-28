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

int n, bt; // BT: Max time overlap
pair<string, string> b; // Represents the best time

int time_to_min(string t) {
    int add = 0;
    if (t[5] == 'P') add = 12;
    string hr;
    hr += t[0]; hr += t[1];
    string min;
    min += t[3]; min += t[4];
    if (hr == "12" && t[5] == 'P') return (stoi(hr)) * 60 + stoi(min);
    return (stoi(hr) + add) * 60 + stoi(min);
}


int main() {
    string c1, c2;
    cin >> c1 >> c2;

    int bst, ben;
    bst = time_to_min(c1);
    ben = time_to_min(c2);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c1 >> c2;
        int nst = time_to_min(c1), nen = time_to_min(c2);
        int overlap = min(ben, nen) - max(nst, bst);
        if (overlap > bt) {
            bt = overlap;
            b.fi = c1; b.se = c2;
        }
    }

    if (bt == 0) cout << "Call in a sick day." << el;
    else cout << b.fi << " " << b.se << el;

}
