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
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pq priority_queue

#define ll long long

#define str string

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

#define usei unordered_set<int>
#define usepi unordered_set<pair<int, int>>

#define mii map<int, int>
#define mpii map<int, pair<int, int>>


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------

const int MM = 1e6 + 2;

int n, m;
usei pot = {1};
vi a[MM];
usei temp;
vi pr;

void ans() {
    for (int i = 1; i <= m; i++) {
        int k = a[i].size();
        bool t = false;
        temp.clear();
        for (int j = 0; j < k; j++) {

            int s = a[i][j];

            temp.insert(s);

            if (pot.contains(s)) t = true;


        }

        if (t) pot.insert(temp.begin(), temp.end());
    }
}


int main() {

    fastio();

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        bool t = false;
        temp.clear();
        for (int j = 1; j <= k; j++) {

            int s; cin >> s;
            a[i].eb(s);

            temp.insert(s);

            if (pot.contains(s)) t = true;


        }

        if (t) pot.insert(temp.begin(), temp.end());
    }

    for (int i = 0; i < m; i++) ans(); // lolwut this was a brute-force joke answer (???)


    for (auto e : pot) pr.eb(e);

    sort(pr.begin(), pr.end());

    cout << pr.size() << el;

    for (int i = 0; i < pr.size(); i++) {
        if (i != pr.size()) cout << pr[i] << " ";
        else cout << pr[i] << el;
    }

}