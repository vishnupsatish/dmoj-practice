#include <iostream>

using namespace std;


int d[10000001], N, s, f, ans;

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s >> f;
        d[s] += 1;
        d[f] -= 1;
    }

    for (int i = 1; i < 10000001; i++) {
        d[i] += d[i - 1];
        ans = max(ans, d[i]);
    }

    cout << ans << endl;


}