#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>

#define pi pair<int, int>
#define pl pair<long long, long long>
#define mp make_pair

#define el "\n"

#define pb push_back

#define pq priority_queue

#define ll long long

using namespace std;


int N, M;
vector<int> adj[2000002];

double dp[1000002];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    adj[0].push_back(1);

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dp[1] = 1;


    for (int i = 1; i <= N; i++) {
        for (int a: adj[i]) {
            dp[a] += dp[i] / (double) adj[i].size();
        }
    }

    for (int i = 1; i <= N; i++) {
        if (adj[i].empty()) printf("%0.9f \n", dp[i]);
    }

    return 0;


}
