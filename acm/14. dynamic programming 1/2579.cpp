#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[10001], stair[10001];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	// dp[i] : i번째 계단을 밟을 떄 점수 최댓값
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
	}
	cout << dp[N];

	return;
}

/*

1 : 10
2 : 30
3 : 35
4 : 55


dp[i] = max(dp[i-2] + dp[i], dp[i-3] + dp[i])
// i번째 계단을 밟으려면
// i-3번째 계단을 밟고, i-2번째 계단을 밟고, i-1번째 계단을 밟지 않고 i번째 계단을 밟음
// i-3번째 계단을 밟고, i-1번째 계단을 밟고, i번째 계단을 밟음.




*/