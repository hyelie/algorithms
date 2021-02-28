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
	cout << "hello, world!" << endl;
	int N; cin >> N; int a, b;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[i] = b;
	}
	
	// arr의 LIS
	// 1. n^2 DP
	// dp[i] : i번째 수를 마지막으로 가지는 LIS의 길이.
	vector<int> DP1(N, 0);
	for (int i = 0; i < N; i++) {
		if (DP1[i] == 0) DP1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {

			}
		}
	}

	return;
}