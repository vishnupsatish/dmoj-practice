#include <limits.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

string s;

int dp[302][302];


int get(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']')) return 0;
    return 2;


}


int main() {
    cin >> s;
    int N = s.length();


    for (int len = 0; len < N; len++) {
        for (int L = 0; L <= N - len; L++){
            int R = L + len;
            if (len == 0) {
                dp[L][R] = 1;
            }
            else if (len == 1) {
                dp[L][R] = get(s[L], s[R]);
            }
            else {
                if (get(s[L], s[R]) == 0) {
                    dp[L][R] = dp[L + 1][R - 1];
                }
                else {
                    dp[L][R] = INT_MAX;
                }
                for (int m = L; m < R; m++) {
                    dp[L][R] = min(dp[L][R], dp[L][m] + dp[m + 1][R]);
                }

            }
        }
    }


    cout << dp[0][N - 1] << endl;



}