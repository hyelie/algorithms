#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (n == 1) break;
		while (n % i == 0) {
			n /= i;
			cout << i << '\n';
		}
	}

	return;
}