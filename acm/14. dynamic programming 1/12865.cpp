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
	int N, K; cin >> N >> K;
	vector<int> value(K+1, 0), weight(K+1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
	}
	vector<vector<int>> dp(N+1, vector<int>(K + 1));
	// dp[i][j] : 물품 i번재까지 봤을 때, 무게 j만큼 들 때 최대 가치
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= K; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= weight[i]) {
				dp[i][j] = max(dp[i-1][j - weight[i]] + value[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
}

/*
	dp[i][j] = 
*/



















/*
void solve() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> v(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	// first는 무게, second는 가치

	vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i <= N; i++) {
		DP[i][0] = 0;
	}
	for (int i = 0; i <= K; i++) {
		DP[0][i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= v[i].first) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - v[i].first] + v[i].second);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	cout << DP[N][K] << endl;

	//O(NK)
	// DP[i][j] : 1부터 i번째 물건까지, jkg까지 들 수 있을 때 최대로 챙길 수 있는 가치.

	// DP[i][j] = DP[i-1][j], DP[i-1][j-v[i].first] + v[i].second
	// 앞 식 : 물건 못들 때
	// 뒷 식 : 물건 들 때 -> 들 수 있어야 함. 어떻게 들 수 있음을 판별하지? j >= v[i].first

	return;
}*/