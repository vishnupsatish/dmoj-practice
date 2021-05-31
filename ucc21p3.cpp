#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>


using namespace std;

const int MM = 1e7 + 2;

int a[MM], x, y, N, R;
ll ans;

int main() {
    cin >> N >> x >> y >> R;

    for (int i = 0; i < R; i++) {
        int l, r;
        cin >> l >> r;
        if ((l < x && r < x) || (l > y && r > y)) continue;
        if (l < x && r > y) ans += (y - x + 1);
        if (l >= x && r > y) ans += (y - l + 1);
        if (l < x && r <= y) ans += (r - x + 1);
        if (l >= x && r <= y) ans += (r - l + 1);
    }

    cout << ans << el;


    return 0;
}