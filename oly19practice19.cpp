#include <iostream>
#include <algorithm>

using namespace std;

int a[1000003];
int mod[1000003];
int max_mod[1000003];
int min_mod[1000003];

int ans = 0;

int main() {

    int N, K;
    cin >> N >> K;

    fill(begin(min_mod), begin(min_mod) + K + 2, 100000000);


    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        mod[i] = (mod[i - 1] + a[i]) % K;

        min_mod[mod[i]] = min(min_mod[mod[i]], i);
        max_mod[mod[i]] = max(max_mod[mod[i]], i);

        int x = mod[i] != 0 ? max_mod[mod[i]] - min_mod[mod[i]] : max_mod[mod[i]];

        ans = max(ans, x);
    }

    cout << ans << "\n";

}

