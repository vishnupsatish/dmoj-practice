#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

#define pi pair<int, int>
#define fi first
#define se second
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

#define vi vector<int>
#define vpi vector<pi>


using namespace std;

int K, Q, D, M, a[5003]; ll n; vector<ll> path; unordered_set<ll> vis; bool recur = 0;


bool dfs(ll n) {
    if (n == 0 && recur) return true;
    if (vis.count(n)) return false;
    vis.insert(n); recur = true;
    for (int i = 0; i<D; i++) {
        if ((n - a[i]) % K == 0) {
            if (dfs((n - a[i]) / K)) {path.push_back(a[i]); return true;}
        }
    }
    return false;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> Q >> D >> M;

    for (int i = 0; i < D; i++) cin >> a[i];
    for (int i = 1; i <= Q; i++) {
        cin >> n; path.clear(); vis.clear(); recur = 0;
        if (!dfs(n)) cout << "IMPOSSIBLE\n";
        else {
            for (int j = 0; j<path.size(); j++) {
                cout << path[j] << (j == (int)path.size()-1 ? "\n": " ");
            }
        }
    }

    return 0;


}
