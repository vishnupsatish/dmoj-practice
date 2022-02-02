#include <bits/stdc++.h>

using namespace std;

// Nice problem: https://imgur.com/a/FS7pY5u

const int MAXN = 1e5 + 3;

int n, totient[MAXN], ans;
bool used[MAXN];


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    n++;

    // CP-algorithms
    totient[0] = 0;
    totient[1] = 1;
    for (int i = 2; i <= 1e5; i++)
        totient[i] = i - 1;

    for (int i = 2; i <= 1e5; i++)
        for (int j = 2 * i; j <= 1e5; j += i)
            totient[j] -= totient[i];

    used[1] = true;

    for (int i = 1; i <= n; i++) {
        int e; cin >> e;

        unordered_set<int> div;

        for (int d = 1; d <= sqrt(e); d++) {
            if (!(e % d)) {
                div.emplace(d);
                div.emplace(e / d);
            }
        }

        for (auto d : div) {
            if (!used[d]) {
                used[d] = true;
                ans += totient[d];
            }
        }
    }

    cout << ans << '\n';
}


