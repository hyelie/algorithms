#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int M, N;
// int board[N][M]
int board[1001][1001], dist[1001][1001];
pii adjacent[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> M >> N;

	queue<pii>q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			dist[i][j] = -1;
			if (board[i][j] == 1) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	pii temp, nxt;
	int max_day = 0;
	while (!q.empty()) {
		temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			nxt.first = temp.first + adjacent[i].first;
			nxt.second = temp.second + adjacent[i].second;
			if (0 <= nxt.first && nxt.first < N && 0 <= nxt.second && nxt.second < M && board[nxt.first][nxt.second] == 0) {
				q.push(nxt);
				board[nxt.first][nxt.second] = 1;
				dist[nxt.first][nxt.second] = dist[temp.first][temp.second] + 1;
				max_day = max(max_day, dist[nxt.first][nxt.second]);
			}
		}
	}

	bool allDone = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				allDone = false;
			}
		}
	}

	if (allDone) {
		cout << max_day;
	}
	else cout << "-1";

	return;
}