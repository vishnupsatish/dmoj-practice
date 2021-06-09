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
#define vpi vector<pair<int, int>>
#define vpl vector<pair<long long, long long>>
#define pb push_back
#define eb emplace_back

#define di deque<int>

#define qi queue<int>
#define qpi queue<pair<int, int>>

#define spi stack<pair<int, int>>

#define ti3 tuple<int, int, int>
#define tll3 tuple<long long, long long, long long>
#define mt make_tuple

#define dqi deque<int>

#define sei set<int>
#define sepi set<pair<int, int>>

#define mii unordered_map<int, int>

using namespace std;


//---------------End of template-------------------------------

const int MM = 100001;

int n, m, dsu[MM];
vi mst;
sei uni;



int find(int e) {
    if (e != dsu[e]) {
        dsu[e] = find(dsu[e]);
    }
    return dsu[e];
}


int main() {


    cin >> n >> m;

    for (int i = 1; i <= n; i++) dsu[i] = i;


    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) {
            mst.eb(i);
            dsu[find(a)] = find(b);
        }
    }

    for (int i = 1; i <= n; i++) uni.emplace(find(i));

    if (uni.size() > 1) {
        cout << "Disconnected Graph" << el;
        return 0;
    }

    for (auto e : mst) {
        cout << e << el;
    }

    return 0;

}
