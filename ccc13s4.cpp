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

int n, m, s, e, vis[1000001];
vi g_ad[1000001], l_ad[1000001];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        g_ad[n1].eb(n2);
        l_ad[n2].eb(n1);
    }

    cin >> s >> e;

    qi q;
    q.emplace(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == e) {
            cout << "yes" << el;
            return 0;
        }
        for (auto v : g_ad[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    memset(vis, 0, sizeof(vis));


    q.emplace(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == e) {
            cout << "no" << el;
            return 0;
        }
        for (auto v : l_ad[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    cout << "unknown" << el;

}