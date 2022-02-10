#include <bits/stdc++.h>

using namespace std;

// Observations; guessforces

int k;


long long calc(long long num) {
    return (long long)(num * ((long double)(1 + num) / 2.0)) + 1ll;
}


int calc_cuts() { // How many cuts do we need to make?
    int l = 0, r = 10000;

    while (l < r) {
        int mid = (l + r) / 2;
        if (calc(mid) >= k) r = mid;
        else l = mid + 1;
    }

    return l;
}


int main() {
    cin >> k;

    int cuts = calc_cuts();
    
    cout << cuts << '\n';
    for (int i = 1; i <= cuts; i++) {
        cout << 5000 - i << ' ' << -5000 << ' ' << -5000 << ' ' << -5000 + i << '\n';
    }
}
