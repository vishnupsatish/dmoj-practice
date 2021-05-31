#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
ll n, w; vector<ll> wid, cute, dp; char op;
int main() {
    cin >> n >> w;
    wid.push_back(0); cute.push_back(0); dp.push_back(0);
    for (int i=1, p, c; i<=n; i++) {
        cin >> op;
        if (op == 'A') {
            cin >> p >> c;
            wid.push_back(wid.back() + p);
            cute.push_back(cute.back() + c);
            int pos = lower_bound(wid.begin(), wid.end(), wid.back()-w) - wid.begin();
            ll ans = max(dp.back(), cute.back() - cute[pos]);
            cout << ans << "\n"; dp.push_back(ans);
        }
        else {
            wid.pop_back(); cute.pop_back(); dp.pop_back();
        }
    }
}