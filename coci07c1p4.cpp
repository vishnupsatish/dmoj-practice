#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e5;
int n;
const int M = 202;
ll dp[M][M];
string s;

int get(char a, char b) {
    if (a == b && a == '?') return 3;
    if (a == '?' && (b == ')' || b == ']' || b == '}') || b == '?' && (a == '(' || a == '[' || a == '{') || (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}')) return 1;
    return 0;
}

ll fun(int L, int R) {
    if (L >= R) return 1;
    if (dp[L][R] != -1) return dp[L][R];
    ll &ret = dp[L][R]; ret = 0;

    for (int m = L + 1; m <= R; m += 2) {
        int coeff = get(s[L], s[m]);
        ret += fun(L + 1, m - 1) * fun(m + 1, R) * coeff;
        if (ret >= mod) ret = ret % mod + mod;
    }

    return ret;

}


int main() {
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));

    ll ans = fun(0, n-1);

    if (ans >= mod) cout << setw(5) << setfill('0') << ans % mod << endl;
    else cout << ans << endl;

}