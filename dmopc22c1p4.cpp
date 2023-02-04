/**
*  author:  vishnus
*  created: 2023-02-04
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: first, arrange the indices of the cards that were added in the order of which they
// were added. Set the first-in-order card to have a value of 1. If the next card was added
// before the current card, then the current card was added after the next card and that
// means the next and current cards can have the same value. The opposite is true if the
// next card was added after the current card.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, t;
  cin >> n >> k >> t;
  while (t--) {
    vector<int> b(n);
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      pos.insert(pos.begin() + b[i], i);
    }
    vector<int> cnt(k + 1);
    int cur = 1;
    cnt[1]++;
    for (int i = 1; i < n; i++) {
      if (pos[i] > pos[i - 1]) {
        cnt[++cur]++;
      } else {
        cnt[cur]++;
      }
    }
    for (int i = 1; i <= k; i++) {
      cout << cnt[i] << (i == k ? '\n' : ' ');
    }
  }
}
