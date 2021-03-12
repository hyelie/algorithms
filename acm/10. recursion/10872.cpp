#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int factorial(int n) {
	if (n == 1) return 1;
	else return n * factorial(n - 1);
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n;
	cin >> n;
	if (n == 0) cout << "1\n";
	else cout << factorial(n);
}