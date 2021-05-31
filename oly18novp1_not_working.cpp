#include <iostream>
#include <vector>
#include <queue>
#include <functional>


#define pi pair<int, int>
#define mp make_pair

#define pb push_back

#define pq priority_queue


using namespace std;

int N, l, r, ans = 1, fi, num;

vector<pi> a;
pq<pi, vector<pi>, greater<pi> > q;

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        a.pb(mp(l, r));
    }

    sort(a.begin(), a.end());

    q.push(mp(a[0].second, 1));


    for (int i = 1; i < N; i++) {

        l = a[i].first; r = a[i].second;
        fi = q.top().first;
        num = q.top().second;

        if (fi > l) {
            q.push(mp(r, -1));
        }
        else {
            q.pop();
            q.push(mp(r, -(num + 1)));
            ans = max(ans, abs(num + 1));
        }

    }

    cout << ans << endl;

}