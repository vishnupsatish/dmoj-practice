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

#define mt make_tuple

#define dq deque<int>

#define uset unordered_set


using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------

const int MM = 10;

int t, n;
vector<int> mot, br, la;

int main() {
    cin >> t;
    for (int _ = 0; _ < t; _++) {

        mot.clear(); br.clear(); la.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            mot.eb(a);
        }

        int cur = 1;
        int a, b;

        while (true) {

            if (!mot.empty()) {
                a = mot.back();
                if (a == cur) {
                    la.eb(a);
                    mot.pop_back();
                    cur++;
                    continue;
                }
            }

            if (!br.empty()) {
                b = br.back();
                if (b == cur) {
                    la.eb(b);
                    br.pop_back();
                    cur++;
                    continue;
                }
            }


            if (!mot.empty()) {
                a = mot.back();
                br.eb(a);
                mot.pop_back();
            }

            if (mot.empty() && br.empty()) break;

            if (mot.empty() && br.back() != cur) break;

        }

        cout << (la.size() == n ? "Y" : "N") << el;

    }
}


