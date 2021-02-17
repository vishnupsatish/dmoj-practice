#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//typedef vector <pair<int, long long > > vecpair;

//long long sol[101][100001];

//long long sol[10100100];

//
//long long knapsack(int W, vecpair items) {
//
//    if (W == 0 || items.empty()) {
////        sol[items.size()][W] = 0;
////        sol[items.size() * W] = 0;
//        return 0;
//    }
//
//    int weight = items.front().first;
//    long long value = items.front().second;
//
//
////    if (sol[items.size() * W] != 0) {
//////        return sol[items.size()][W];
////return sol[items.size() * W];
////    }
//
//
//    vecpair new_vec;
//    new_vec = vecpair(items.begin() + 1, items.end());
//
//
//    if (weight > W) {
////        sol[items.size() * W] = knapsack(W, new_vec);
////        return sol[items.size() * W];
//        return knapsack(W, new_vec);
//
//    } else {
////        long long a1 = value + knapsack(W - weight, new_vec);
////        long long a2 = knapsack(W, new_vec);
//
//
////        sol[items.size() * W] = max(value + knapsack(W - weight, new_vec), knapsack(W, new_vec));
////        return sol[items.size() * W];
//        return max(value + knapsack(W - weight, new_vec), knapsack(W, new_vec));
//
//
//    }
//}

int main() {

    cin.sync_with_stdio(0); cin.tie(0);
//    vecpair items;
    int N, W;


    long long sol[10000];

    cin >> N >> W;

    for (int i = 0; i < N; i++) {

        long long w;
        int v;
        cin >> w >> v;

        for (int wt = W; wt >= w; wt--) {
            sol[wt] = max(sol[wt], sol[wt - w] + v);
        }



//        items.push_back(make_pair(w_, v));
    }
    cout << sol[W] << "\n";


//    cout << knapsack(W, items) << "\n";

    return 0;
}
