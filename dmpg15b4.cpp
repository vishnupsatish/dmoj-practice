#include <iostream>
#include <algorithm>
#include <vector>

#define eb emplace_back

using namespace std;

const int MAXN = 32;

int n, ans = 1, zero;
vector<int> pos, neg;


int main() {
	cin >> n;
	
	if (n == 1) {
		int a; cin >> a; cout << a << "\n";
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a > 0) pos.eb(a);
		else if (a < 0) neg.eb(a);
		else zero++;
	}
	
	if (pos.empty() && neg.empty()) {
		cout << 0 << "\n";
		return 0;
	}
	
	if (pos.empty() && zero) {
		cout << 0 << "\n";
		return 0;
	}
	
	sort(neg.begin(), neg.end());
	
	for (auto &e : pos) ans *= e;
	
	int neg_to_go = (neg.size() % 2 == 0 ? neg.size() : neg.size() - 1);
	
	for (int i = 0; i < neg_to_go; i++) ans *= neg[i];
	
	cout << ans << "\n";
		
	
	
}