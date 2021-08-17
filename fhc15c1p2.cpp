#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
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
#endif

#define fastio() cin.tie(0);ios::sync_with_stdio(0);
#define fi first
#define se second
#define el "\n"
#define ll long long
#define ld long double
#define vi vector<int>
#define eb emplace_back
#define uset unordered_set
#define umap unordered_map

using namespace std;

const int NINF = -0x3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

//---------------End of template-------------------------------

struct node { node *ch[26]; };
int T, n, ans;  string s;


void insert(string &s, node *root) {
    node *cur = root; bool prefix = true; int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        if (prefix) cnt++;
        if (cur->ch[c] == nullptr) {
            cur->ch[c] = new node(); prefix = false;
        }
        cur = cur->ch[c];
    }
    ans += cnt;
}


void remove(node *root) {
    if (root == nullptr) return;
    for (auto c : root->ch) remove(c);
    delete root; root = nullptr;
}


int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        cin >> n; ans = 0;
        node *root = new node();
        for (int i = 1; i <= n; i++) {
            cin >> s;
            insert(s, root);
        }
        cout << ans << el;
        remove(root);
    }

}