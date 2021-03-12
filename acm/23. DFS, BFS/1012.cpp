#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int M, N, K;
pii adjacent[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void solve();
void BFS(int x, int y, vector<vector<int>>& board, vector<vector<bool>>& visited) {
	visited[x][y] = true;
	queue<pii> q;
	q.push({ x, y });

	pii temp, nxt;
	while (!q.empty()) {
		temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			nxt.first = temp.first + adjacent[i].first;
			nxt.second = temp.second + adjacent[i].second;
			if (0 <= nxt.first && nxt.first < N && 0 <= nxt.second && nxt.second < M && !visited[nxt.first][nxt.second] && board[nxt.first][nxt.second]) {
				q.push(nxt);
				visited[nxt.first][nxt.second] = true;
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

void solve() {
	cin >> M >> N >> K;
	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	int x, y, cnt = 0;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		board[y][x] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && board[i][j]) {
				BFS(i, j, board, visited);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';


	return;
}