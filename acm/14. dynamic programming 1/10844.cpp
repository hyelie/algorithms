#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define MYDIV 1000000000

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
// dp[i][j] : 길이가 i이고 끝자리가 j인 거울수 개수
int dp[101][10];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 0;
		dp[1][i] = 1;
	} dp[1][0] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1]%MYDIV + dp[i - 1][j + 1] % MYDIV) % MYDIV;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[N][i];
		sum %= MYDIV;
	}
	



	cout << sum;

	return;
}