#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int board[501][501];
int dp[501][501];

int M, N;
pii neighbor[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void solve();
// 역추적 할 것임.
int search(int x, int y) {
	// 도착지에 도착한 경우
	if (x == 0 && y == 0) {
		return 1;
	}

	// 첫 방문이 아닌경우
	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	// 첫 방문인 경우
	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int prevx = x + neighbor[i].first;
		int prevy = y + neighbor[i].second;

		// 이전값은 현재값보다 커야함 그래야 path가 존재
		if (0 <= prevx && prevx < M && 0 <= prevy && prevy < N && board[prevx][prevy] > board[x][y]) {
			dp[x][y] += search(prevx, prevy);
		}
	}

	return dp[x][y];
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> M >> N;
	//board[M - 1][N - 1] = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << search(M-1, N-1)<<endl;

	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j]<<' ';

		}cout << endl;
	}*/

	

	return;
}

/*

어떤 칸의 경로 개수
인접한 칸(상하좌우)의 경로 합

*/