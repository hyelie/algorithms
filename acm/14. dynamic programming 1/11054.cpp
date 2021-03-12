#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int arr[1001], dp[1001][2];
// dp[i][0]은 앞에서부터 뒤로가는 LIS 길이, dp[i][1]은 뒤에서부터 앞으로가는 index i를 마지막으로 갖는 LIS 길이

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		dp[i][0] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		dp[i][1] = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}

	int maxlen = -1;
	for (int i = 0; i < N; i++) {
		maxlen = max(maxlen, dp[i][0] + dp[i][1] - 1);
	}
	cout << maxlen;

	return;
}