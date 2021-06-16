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

#define sei unordered_set<int>
#define sepi unordered_set<pair<int, int>>

#define mii map<int, int>
#define mpii map<int, pair<int, int>>

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;

//---------------End of template-------------------------------


vi a;
string s;
map<char, int> num = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };



void vectorize() {
    string cur = "";
    cur += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (cur[0] == s[i]) {
            cur += s[i];
        } else {
            a.eb(num[cur[0]] * cur.length());
            cur = s[i];
        }
    }
    a.eb(num[cur[0]] * cur.length());
}


int main() {

    for (int _ = 0; _ < 5; _++) {
        a.clear();
        cin >> s;
        vectorize();
        int n = a.back();
        for (int i = a.size() - 2; i >= 0; i--) {
            if (a[i] < n) n = n - a[i];
            else n += a[i];
        }
        cout << n << el;

    }

}
