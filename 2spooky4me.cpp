#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int n, l, S, a, b, s, prev_val, prev_key, ans;
map<int, int> diff;

int main() {

    cin >> n >> l >> S;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> s;
        diff[a] += s;
        diff[b + 1] -= s;
    }

    prev_val = 0;
    prev_key = 0;


    for (auto &k : diff) {
        k.second = k.second + prev_val;
        if (prev_val < S) {
            ans += k.first - prev_key;
        }
        prev_val = k.second;
        prev_key = k.first;
    }

    if (abs(diff.end()->second) < S) {
        ans += l - prev_key;
    }

    cout << ans << endl;


    return 0;

}