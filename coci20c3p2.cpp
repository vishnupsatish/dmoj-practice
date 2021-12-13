#include <bits/stdc++.h>

using namespace std;

// Use game theory and tries. If someone makes a move where
// that moves results in a win, they will only make that move.

struct node { node *ch[26]; };
unordered_set<char> start_a;

int n, m;

bool play(int index, char current, node *ni, node *em) { // Returns 1 if the current player wins
    bool win = false;
    if (index & 1) { // If it is Emilija's move
        // First check if Emilija cannot make a move
        if (em->ch[current - 'a'] == nullptr) return 0;
        // If Emilija can make a move, make that move then allow Nina to make a move
        node *cur_move = em->ch[current - 'a'];
        for (int i = 0; i < 26; i++) {
            if (cur_move->ch[i] != nullptr) {
                win |= !play(index + 1, i + 'a', ni, cur_move->ch[i]);
            }
        }
        return win;
    } else { // If it's Nina's move
        // First check if Nina cannot make a move
        if (ni->ch[current - 'a'] == nullptr) return 0;
        node *cur_move = ni->ch[current - 'a'];
        // If Nina can make a move, make that move then allow Emilija to make a move
        for (int i = 0; i < 26; i++) {
            if (cur_move->ch[i] != nullptr) {
                win |= !play(index + 1, i + 'a', cur_move->ch[i], em);
            }
        }
        return win;
    }
}


void insert(string &s, node *root) {
    node *cur = root;
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        if (cur->ch[c] == nullptr) cur->ch[c] = new node();
        cur = cur->ch[c];
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    node *ni = new node();
    while (n--) {
        string s; cin >> s;
        insert(s, ni);
        start_a.emplace(s[0]);
    }

    cin >> m;
    node *em = new node();
    while (m--) {
        string s; cin >> s;
        insert(s, em);
    }

    bool nina_win = false;

    for (auto c: start_a) {
        nina_win |= !play(1, c, ni->ch[c - 'a'], em);
    }

    if (nina_win) cout << "Nina" << '\n';
    else cout << "Emilija" << '\n';
}
