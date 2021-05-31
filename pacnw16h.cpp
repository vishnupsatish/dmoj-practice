#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <bitset>

#define pi pair<int, int>
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

using namespace std;


ll N;
int K;
ll dp[200001];
vector<tuple<ll, ll>> a;


int main() {

    cin >> N >> K;

    a.emplace_back(0, 0);

    for (int i = 1; i <= K; i++) {
        ll j, k;
        cin >> j >> k;
        a.emplace_back(k, j);
    }

    sort(a.begin(), a.end());


    dp[0] = 0;

    for (int i = 1; i <= K; i++) {
        ll f = get<1>(a[i]);
        ll l = get<0>(a[i]);
        int pos = upper_bound(a.begin(), a.end(), make_tuple(f, 1e19)) - a.begin() - 1;
        dp[i] = max(dp[i - 1], dp[pos] + (l - f + 1));
    }


    cout << N - dp[K] << endl;


    return 0;


}
