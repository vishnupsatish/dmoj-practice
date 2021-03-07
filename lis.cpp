#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<ll> ans;

void binary(ll elem) {
    int left = 0;
    int right = ans.size() - 1;

    ll last_elem = 1000000000000001;

    if (!ans.empty()) {
        last_elem = ans.back();
    }

    if (elem > last_elem) {
        ans.push_back(elem);
        return;
    }

    while (left < right) {
        int mid = (right + left) / 2;
        if (ans.at(mid) > elem) {
            right = mid;
            continue;
        }
        left = mid + 1;
    }

    ans.at(left) = elem;
    return;


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    vector<ll> seq;

    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;

        seq.push_back(a);
    }

    ans.push_back(seq[0]);

    for (int i = 0; i < N; i++) {
        binary(seq[i]);
    }

    cout << ans.size() << "\n";



    return 0;
}