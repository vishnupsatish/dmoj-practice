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

const int MM = 12;

int r, c, cl, cr, cu, cd, a[MM][MM], n[MM][MM];

int get_sea_neighbours(int i, int j) {
    return !a[i + 1][j] + !a[i - 1][j] + !a[i][j + 1] + !a[i][j - 1];
}


int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) { // cin
        for (int j = 1; j <= c; j++) {
            char t; cin >> t;
            a[i][j] = t == 'X' ? 1 : 0;
        }
    }

    for (int i = 1; i <= r; i++) { // remove ones with >= 3 sea neighbours
        for (int j = 1; j <= c; j++) {
            if (a[i][j] && get_sea_neighbours(i, j) >= 3) n[i][j] = 0;
            else n[i][j] = a[i][j];
        }
    }

    for (int i = 1; i <= r; i++) { // Find first row that has X from up
        cu = i;
        for (int j = 1; j <= c; j++) {
            if (n[i][j]) {
                cu--;
                break;
            }
        }
        if (cu < i) break;
    } cu++;

    for (int i = r; i >= 1; i--) { // Find first row that has X from down
        cd = i;
        for (int j = 1; j <= c; j++) {
            if (n[i][j]) {
                cd++;
                break;
            }
        }
        if (cd > i) break;
    } cd--;


    for (int j = 1; j <= c; j++) { // Find first column that has X from left
        cl = j;
        for (int i = 1; i <= r; i++) {
            if (n[i][j]) {
                cl--;
                break;
            }
        }
        if (cl < j) break;
    } cl++;

    for (int j = c; j >= 1; j--) { // Find first column that has X from right
        cr = j;
        for (int i = 1; i <= r; i++) {
            if (n[i][j]) {
                cr++;
                break;
            }
        }
        if (cr > j) break;
    } cr--;

    for (int i = cu; i <= cd; i++) { // Print it
        for (int j = cl; j <= cr; j++) {
            cout << (n[i][j] ? "X" : ".");
        }
        cout << el;
    }


}