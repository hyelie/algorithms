#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
long long dp[31][31];
// 조합이네. MCN

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	int N;
	cin >> N;

	// comb[i][j] : iCj
	dp[0][0] = 0;
	dp[1][1] = dp[1][0] = 1;
	for (int i = 2; i <= 30; i++) {
		dp[i][0] = dp[i][i] = 1;
	}

	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}


	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	int N, M; cin >> N >> M;
	cout << dp[M][N] << '\n';

	return;
}