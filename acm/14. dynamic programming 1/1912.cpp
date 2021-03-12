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
	int n; cin >> n;
	vector<int> arr(n), DP(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	DP[0] = arr[0];
	for (int i = 1; i < n; i++) {
		DP[i] = max(DP[i - 1] + arr[i], arr[i]);
	}
	cout << *max_element(DP.begin(), DP.end()) << endl;

}


// 연속합.
// DP[i] : i번째 index까지 최대 수.