#include <iostream>
#include <vector>

#define pi pair<int, int>
#define mp make_pair

#define pb push_back

#define pq priority_queue


using namespace std;

int N, l, r, ans = 1, p;

vector<pi> a;

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        a.pb(mp(r, l));
    }

    sort(a.begin(), a.end());

    p = a[0].first;

    for (int i = 1; i < N; i++) {
        l = a[i].second;
        r = a[i].first;

        if (l >= p) {
            ans ++;
            p = r;
        }
    }


    cout << ans << endl;

}
