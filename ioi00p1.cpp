#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[2][5003];


int main() {

    int N;
    cin >> N;

    string s1;
    cin >> s1;

    string s2 = s1;

    reverse(s2.begin(), s2.end());

    int ok = 0;
    int prev = !ok;

    for (int m = 1; m <= N; m++) {
        ok = m % 2;
        prev = !ok;
        for (int n = 1; n <= N; n++) {
            if (s1[m - 1] == s2[n - 1]) {
                dp[ok][n] = dp[prev][n - 1] + 1;
            }
            else {
                dp[ok][n] = max(dp[prev][n], dp[ok][n - 1]);
            }
        }
    }

    cout << N - dp[ok][N] << endl;

    return 0;
}