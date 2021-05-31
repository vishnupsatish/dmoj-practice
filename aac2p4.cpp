#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n, t;
vector<int> a;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> t;

    for (int te = 0; te < t; te++) {
        a.clear();

        cin >> n;

        a.push_back(0);

        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            a.push_back(b);
        }

        sort(a.begin(), a.end());


        if (a[1] == a[n] && n % 2 == 0) {
            cout << "-1" << "\n";
        } else if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) {
                cout << a[n / 2 + i] << " ";
                if (i == n / 2) cout << a[i] << "\n";
                else cout << a[i] << " ";
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (i == n) cout << a[i] << "\n";
                else cout << a[i] << " ";
            }
        }

    }

    return 0;
}