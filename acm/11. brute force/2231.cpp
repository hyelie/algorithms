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
	int N; cin >> N;

	for (int i = 1; i < N; i++) {
		int sum = i;
		int temp = i;
		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N) {
			cout << i << '\n';
			return;
		}
	}
	cout << '0' << '\n';

	return;
}

// 198 + 1 + 9 + 8 = 216
// 생성자 : 주어진 수보다는 작다.