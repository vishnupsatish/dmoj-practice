#include <iostream>
#include <vector>
#include <map>

#define ll int

using namespace std;

vector<ll> ans;

void binary(ll elem) {
    int left = 0;
    int right = ans.size() - 1;

    ll last_elem = 1000000001;

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

    vector<ll> seq1;

    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        seq1.push_back(a);
    }

    cin >> N;

    map<int, int> seq2_map;

    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        seq2_map.insert({a, i});
    }

    vector<ll> lis;

    for (int i = 0; i < seq1.size(); i++) {
        if (seq2_map.find(seq1.at(i)) != seq2_map.end()) {
            lis.push_back(seq2_map.at(seq1.at(i)));
        }
    }

    if (lis.size() == 0) {
        cout << 0 << "\n";
        return 0;
    }

    ans.push_back(lis.at(0));

    for (int i = 0; i < lis.size(); i++) {
        binary(lis.at(i));
    }

    cout << ans.size();


    return 0;
}