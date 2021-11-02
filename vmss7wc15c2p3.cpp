#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 3;

#define ll long long

int n;
ll h[MAXN], ans;
vector<pair<ll, ll>> ms;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> h[i];

    for (int i = 0; i < n; i++) {
        ll no = 1;
        while (!ms.empty()) {
            if (h[i] == ms.back().first) { // If they're equal, add the element's second element in the pair,
                                           // since you can see all of the "same value" consecutive elements in
                                           // the stack, and maybe there's a 2, meaning you can see the previous
                                           // one before the consecutive "same values" but nothing before
                ans += ms.back().second;
                no = ms.back().second + 1;
                break;
            }
            ans++; // Any two adjacent elements can have a bridge,
                   // and any element that is greater than all elements
                   // in between (that were just popped) can have a bridge
            if (h[i] < ms.back().first) { // Say it was (7, 1), (7, 2) and 3 was to be added,
                                          // don't add the 2 from the 7, just add 1, then break, since the
                                          // previous 7 (with a 1) can't work due to being blocked by the first 7 (with a 2).
                no = 2; // This is done since if the next element has the
                        // same height, then it can make a bridge with the currents
                        // element AND the one previous to the current element
                break;
            }
            ms.pop_back();
        }

        ms.emplace_back(h[i], no);
    }
    cout << ans << "\n";
}