#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;

	// sqrt : cmath include«œ±‚
	for (int i = 1; i < sqrt(N); i++) {
		cout << i << '\n';
		if (i != N / i) {
			cout << N / i << '\n';
		}
	}


	return;
}