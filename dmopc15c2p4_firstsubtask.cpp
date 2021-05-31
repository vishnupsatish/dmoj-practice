#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

#define pi pair<int, int>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue


using namespace std;

deque<tuple<int, int, int>> a;

int N;

int dp[10000001];

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        int R, L, H;
        cin >> R >> L >> H;
        a.push_front(make_tuple(R, L, H));
    }


    for (int i = 0; i < N; i++) {
        int R, L, H;
        R = get<0>(a[i]);
        L = get<1>(a[i]);
        H = get<2>(a[i]);

        dp[R] = max(dp[R + 1], dp[R + L] + H);

        for (int j = N; j >= 0; j--) {
            dp[j] = max(dp[j + 1], dp[j]);
        }
    }



    cout << dp[0] << el;




}
