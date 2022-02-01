#include <bits/stdc++.h>

using namespace std;

// Idea: O(N^2) solution. Be greedy by lexicographically placing the least possible character
// at a position, then check if the remaining letters can be placed in the remaining positions
// using the following algorithm.
// https://imgur.com/a/T0Kc8st

int n;
string m, s, ans;
unordered_map<char, int> cs; // How many a, b, c are there in letters to choose?
unordered_map<char, int> mir; // How many a, b, c are there in Mirko's string?


bool check() {
    for (int i = 0; i <= min(mir['b'], cs['a']); i++) {
        // Temp
        unordered_map<char, int> tcs = cs;
        unordered_map<char, int> tmir = mir;

        tcs['a'] -= i;
        tmir['b'] -= i;

        if (tmir['c'] < tcs['a']) continue;

        tmir['c'] -= tcs['a'];
        tcs['a'] = 0;

        if (tmir['b'] > tcs['c']) continue;

        tcs['c'] -= tmir['b'];
        tmir['b'] = 0;

        if (tmir['a'] < tcs['c']) continue;

        tmir['a'] -= tcs['c'];
        tcs['c'] = 0;

        if (tmir['a'] + tmir['c'] != tcs['b']) continue;

        return true;
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> s;

    for (auto c : m) cs[c]++;

    for (auto c : s) mir[c]++;

    for (int i = 0; i < n; i++) {
        mir[s[i]]--;

        if (cs['a'] != 0) {
            cs['a']--;
            if (s[i] != 'a' && check()) {
                ans += 'a';
                continue;
            }
            cs['a']++;
        }

        if (cs['b'] != 0) {
            cs['b']--;
            if (s[i] != 'b' && check()) {
                ans += 'b';
                continue;
            }
            cs['b']++;
        }

        if (cs['c'] != 0) {
            cs['c']--;
            if (s[i] != 'c' && check()) ans += 'c';
            else cs['c']++;
        }
    }

    cout << ans << '\n';
}
