#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Important thing to note is that nCr = nC(n-r), so we loop k from 1 to
// (2k)Ck such that (2k)Ck <= x, then for each k binary search the value of n.

int n;


ll choose(ll n_, ll r) {
    if (r > n_ - r) r = n_ - r;
    ll ans = 1;
    for (ll i = 1; i <= r; i++) {
        ans *= n_ - r + i;
        ans /= i;
    }
    return ans;
}


void solve() {
    set<pair<ll, ll>> ans;
    ll x; cin >> x;

    for (ll k = 1; choose(2*k, k) <= x; k++) {
        ll good;
        ll l = 1;
        ll r = 2000000000000000;
        while (l < r) {
            ll mid = (l + r) / 2ll;
            ll c = choose(mid, k);
            if (c < 0) {
                r = mid;
                continue;
            }
            if (c == x) {
                good = mid;
                break;
            }
            if (c > x) {
                r = mid;
            } else{
                l = mid + 1ll;
            }
        }
        if (choose(good, k) == x) {
            ans.emplace(good, k);
            ans.emplace(good, good-k);
        }
    }

    cout << ans.size() << '\n';
    int cnt = 1;
    for (auto [f, s]: ans) {
        cout << "(" << f << "," << s << ")" << (cnt == ans.size() ? '\n' : ' ');
        cnt++;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    while (n--) {
        solve();
    }
}
