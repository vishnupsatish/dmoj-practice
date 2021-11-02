#include <bits/stdc++.h>

using namespace std;

// Idea: use string hashing. Use a set and a freq array, and when the freq arrays are equal,
// add the *hash* of the substring, not the substring itself. Use double hashing, then hash
// *those* together to avoid collision.

const int MAXNH = 2e5 + 3;

string n, h;
long long nl, hl, hs1[MAXNH], hs2[MAXNH], pw1[MAXNH], pw2[MAXNH], mod = 1e9 + 7, base1 = 131, base2 = 137;
unordered_set<long long> ans;
vector<int> fs1(26), fs2(26);

long long get_sub_hash(int l, int r) {
    long long h1 = (hs1[r] - hs1[l - 1] * pw1[r - l + 1] % mod + mod) % mod, h2 = (hs2[r] - hs2[l - 1] * pw2[r - l + 1] % mod + mod) % mod;
    return (h1 << 31ll) | h2;
}


int main() {
    cin >> n >> h;

    nl = n.size(); hl = h.size();

    for (int i = 0; i < nl; i++) fs1[n[i] - 'a']++;

    pw1[0] = 1; pw2[0] = 1;

    for (int i = 1; i <= hl; i++) {
        hs1[i] = (hs1[i - 1] * base1 + h[i - 1]) % mod;
        pw1[i] = pw1[i - 1] * base1 % mod;
        hs2[i] = (hs2[i - 1] * base2 + h[i - 1]) % mod;
        pw2[i] = pw2[i - 1] * base2 % mod;
    }

    for (long long i = 1; i <= hl; i++) {
        fs2[h[i - 1] - 'a']++;
        if (i > nl) fs2[h[i - 1 - nl] - 'a']--;
        if (fs1 == fs2) {
            ans.insert(get_sub_hash(i - nl + 1, i));
        }
    }

    cout << ans.size() << "\n";
}
