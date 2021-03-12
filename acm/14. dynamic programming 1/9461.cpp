#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
long long dp[101];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 6; i < 101; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}


	int T;
	cin >> T;
	while (T--) {
		int N; cin >> N;
		cout << dp[N] << '\n';
	}

	return;
}