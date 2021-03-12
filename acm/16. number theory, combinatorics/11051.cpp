#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 10007

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[1001][1001];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, K; cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[i][i] = dp[i][0] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j] % MOD + dp[i - 1][j - 1] % MOD) % MOD;
		}
	}
	cout << dp[N][K];

	return;
}