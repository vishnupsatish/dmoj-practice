#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <bitset>

#define pi pair<int, int>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

using namespace std;

const ll inf = 1e18;

int n; vector<tuple<ll, ll, ll>> vec; ll s, f, h, dp[100002];




int main() {


    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n; vec.emplace_back(0, 0, 0);

    for (int i=1; i<=n; i++) {
        cin >> s >> f >> h;
        vec.emplace_back(s + f, s, h);
    }

    sort(vec.begin(), vec.end());

    for (int i = 1; i <= n; i++) {
        s = get<1>(vec[i]);
        h = get<2>(vec[i]);
        int pos = upper_bound(vec.begin(), vec.end(), make_tuple(s, inf, inf)) - vec.begin() - 1;
        dp[i] = max(dp[i - 1], h + dp[pos]);
    }

    cout << dp[n] << endl;

    return 0;



}
