#include <bits/stdc++.h>

using namespace std;

int es;
string s, e;
unordered_map<char, int> m; // Maps each character to its respective index in the explosion


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> s >> e;

    es = e.size();

    string ans;

    if (es == 1) {
        for (auto c : s) {
            if (c != e[0]) ans += c;
        }
        cout << (ans.empty() ? "FRULA" : ans) << '\n';
        return 0;
    }

    for (int i = 0; i < es; i++) m[e[i]] = i;

    vector<char> stk;

    for (auto c : s) {
        ans += c;
        if (stk.empty()) {
            if (!m.contains(c)) continue;
            if (m[c] == 0) stk.emplace_back(c);
        } else {
            if (!m.contains(c)) stk.clear();
            else if (m[c] == 0) stk.emplace_back(c);
            else if (m[c] == m[stk.back()] + 1) {
                stk.emplace_back(c);
                if (m[c] == es - 1) { // Last char
                    while (true) {
                        stk.pop_back();
                        ans.pop_back();
                        if (m[stk.back()] == 0) {
                            stk.pop_back();
                            ans.pop_back();
                            break;
                        }
                    }
                }
            }
            else stk.clear();
        }
    }

    cout << (ans.empty() ? "FRULA" : ans) << '\n';
}
