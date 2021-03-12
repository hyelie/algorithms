#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
pii dp[41] = { {0, 0}, };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
	for(int i = 2; i<41; i++){
		dp[i] = { dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second };
	}

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		cout << dp[N].first << " " << dp[N].second << '\n';
	}

	return;
}