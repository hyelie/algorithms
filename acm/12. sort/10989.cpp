#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	vector<int> v(10001, 0);
	int input;
	while (N--) {
		cin >> input;
		v[input]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (v[i] != 0) {
			cout << i << '\n';
			v[i]--;
		}
	}

	return;
}