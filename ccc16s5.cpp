#include <iostream>
#include <string>


using namespace std;


string pre, ne;
long long k;

int n;

const long long one = 1;


string get(string b, long long shift) {
     ne = "";
     int p = shift % n;
     int minusp = (n - p) % n;
     for (int i = 0; i < n; i++) {
         ne += to_string((int)(b[(i + p) % n] - '0') ^ (int)(b[(i + minusp) % n] - '0'));
     }
     return ne;
}


int main() {
    cin >> n >> k >> pre;

    for (long long i = 60; i >= 0; i--) {
        if ((long long)(k >> i) & 1) {
            pre = get(pre, (one << i));
        }
    }

    cout << pre << endl;

}