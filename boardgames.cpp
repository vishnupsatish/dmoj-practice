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

const int MM = 1e7 + 2;

int n, m, vis[MM];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    qpi q;

    q.emplace(n, 0);

    vis[n] = 1;

    while (!q.empty()) {
        int u = q.front().fi;
        int lvl = q.front().se;
        q.pop();
        if (u == m) {
            cout << lvl << el;
            break;
        }
        if ((ll)u * 3ll <= MM) {
            if (!vis[(ll)u * 3ll]) {
                q.emplace(u * 3, lvl + 1);
                vis[u * 3] = 1;
            }
        }
        if (u % 2 == 0 && !vis[u / 2]) {
            q.emplace(u / 2, lvl + 1);
            vis[u / 2] = 1;
        }
        if (u > 1 && !vis[u - 1]) {
            q.emplace(u - 1, lvl + 1);
            vis[u - 1] = 1;
        }
        if (u > 3 && !vis[u - 3]) {
            q.emplace(u - 3, lvl + 1);
            vis[u - 3] = 1;
        }
    }


}