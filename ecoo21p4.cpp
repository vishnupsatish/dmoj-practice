#include <iostream>
#include <vector>

using namespace std;

long long K, sum = 0;
vector<int> f;

int main() {

    cin >> K;
    K ++;

    for (long long i = 2, up = K; i * i <= up; i++) {
        while (K % i == 0 ) {
            f.push_back(i - 1); K /= i; sum += i - 1;
        }
    }

    if (K != 1) { f.push_back(K - 1); sum += K - 1; }
    if (sum > 1e5) { cout << "Sad Chris" << endl; return 0; }
    cout << sum << "\n";
    for (int i =0; i < f.size(); i++) {
        long long num = f[i];
        for (int j = 0; j < num; j++) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";



    return 0;

}