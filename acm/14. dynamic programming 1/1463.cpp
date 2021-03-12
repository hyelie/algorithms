#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[1000001];

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
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = 1000001;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3]+1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2]+1);
		}
		dp[i] = min(dp[i], dp[i - 1]+1);
	}
	cout << dp[N];

	return;
}