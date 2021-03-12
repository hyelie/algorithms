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
	int N, M;
	cin >> N >> M;
	vector<int> cards(N);
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	// result : M과의 차이
	int result = M;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = cards[i] + cards[j] + cards[k];
				if (M < sum) continue;
				result = min(result, M - sum);
			}
		}
	}
	cout << M-result;

	return;
}